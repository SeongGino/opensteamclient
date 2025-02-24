#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "../../interop/appmanager.h"
#include "../../utils/binarykv.h"
#include "../../threading/threadcontroller.h"
#include <QMessageBox>

SettingsWindow::SettingsWindow(QWidget *parent, App *app) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    this->app = app;
    setWindowTitle(QString::fromStdString(app->name).append(" settings"));
    bool compatEnabled = Global_SteamClientMgr->ClientCompat->BIsCompatibilityToolEnabled(app->appid);
    ui->enableProtonBox->setChecked(compatEnabled);
    ui->compatToolBox->setVisible(compatEnabled);
    if (compatEnabled) {
        PopulateCompatTools();
    }
    PopulateBetas();
    ReadLaunchOptions();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::PopulateBetas() {
    ui->betasDropdown->clear();
    dropdownBetas.clear();

    ui->betasDropdown->addItem("NONE - No beta selected");

    std::vector<Beta> betas = app->GetAllBetas();

    if (betas.size() == 0) {
        ui->betasDropdown->setCurrentIndex(0);
        return;
    }

    std::string currentBeta = app->GetCurrentBeta();
    DEBUG_MSG << "[SettingsWindow] beta is " << currentBeta << std::endl;

    for (auto &&beta : betas)
    {
        std::string flags = "";

        //TODO: give the user an option to hide betas they don't have access to
        if (beta.hasAccess) {
            flags.append("Private");
        } else {
            flags.append("Password Required");
        }

        if (!flags.empty()) {
            flags = "[" + flags + "]";
        }
        ui->betasDropdown->addItem(QString("%1 - %2 %3").arg(QString::fromStdString(beta.name), QString::fromStdString(beta.description), QString::fromStdString(flags)));
        dropdownBetas.insert({ui->betasDropdown->count()-1, beta});

        if (beta.name == std::string(currentBeta)) {
            ui->betasDropdown->setCurrentIndex(ui->betasDropdown->count()-1);
        }
    }
}

void SettingsWindow::ReadLaunchOptions() {
    ui->launchOptionsField->setText(QString::fromStdString(std::string(app->GetLaunchCommandLine())));
}

void SettingsWindow::PopulateCompatTools()
{
    ui->compatToolBox->clear();

    int selectedIndex = -1;
    for (auto &&i : app->compatData.validCompatTools)
    {
        ui->compatToolBox->addItem(QString::fromStdString(i.humanName), QVariant(QString::fromStdString(i.name)));
        if (selectedIndex == -1 && app->compatData.isCompatEnabled) {
            if (i.name == app->compatData.currentCompatTool.name) {
                std::cout << "selected compat tool " << i.name << std::endl;
                selectedIndex = ui->compatToolBox->count() - 1;
            }
        }
    }
   
    if (selectedIndex != -1) {
        ui->compatToolBox->setCurrentIndex(selectedIndex);
    }
}

void SettingsWindow::on_enableProtonBox_stateChanged(int arg1)
{
    ui->compatToolBox->setVisible((bool)arg1);
    if ((bool)arg1) {
        PopulateCompatTools();
    } else {
        app->ClearCompatTool();
    }
}



void SettingsWindow::on_compatToolBox_currentIndexChanged(int index)
{
    QString compatToolName = ui->compatToolBox->itemData(index).toString();

    app->SetCompatTool(compatToolName.toStdString());
}

void SettingsWindow::on_testBetaKeyButton_clicked()
{
    if (ui->betaKeyBox->text().isEmpty()) {
        return;
    }

    std::string password = ui->betaKeyBox->text().toStdString();
    Global_SteamClientMgr->ClientAppManager->CheckBetaPassword(app->appid, password.c_str());

    connect(Global_ThreadController->callbackThread, &CallbackThread::CheckAppBetaPasswordResponse, this, &SettingsWindow::betaPasswordResponseReceived, Qt::ConnectionType::SingleShotConnection);
}

void SettingsWindow::betaPasswordResponseReceived(CheckAppBetaPasswordResponse_t resp) {
    QMessageBox msgBox;

    if (resp.eResult == k_EResultFailure) {
        msgBox.setText("Beta password invalid. ");
    } else if (resp.eResult == k_EResultOK) {
        PopulateBetas();
        msgBox.setText("Beta password valid, new betas available.");
    } else {
        msgBox.setText(QString("Unexpected error code ").arg(resp.eResult));
    }
    msgBox.exec();
}

void SettingsWindow::on_betasDropdown_activated(int index)
{
    DEBUG_MSG << "[SettingsWindow] Requested index " << index << std::endl;
    // User selected "No beta"
    if (index == 0) {
        DEBUG_MSG << "[SettingsWindow] index was 0" << std::endl;
        Global_SteamClientMgr->ClientAppManager->SetAppConfigValue(app->appid, "betakey", "public");
        return;
    }

    Beta beta = dropdownBetas.at(index);

    // This calls ResolveDepotDependencies (internally) and also queues the app for immediate update (if installed)
    DEBUG_MSG << "[SettingsWindow] Setting beta to " << beta.name.c_str() << std::endl;
    app->SetCurrentBeta(beta.name);
}

void SettingsWindow::on_uninstallBtn_clicked()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setIcon(QMessageBox::Icon::Question);
    msgBox->setText(QString("Are you sure you wish to uninstall %1?").arg(QString::fromStdString(app->name)));
    msgBox->setStandardButtons(QMessageBox::StandardButtons(QMessageBox::StandardButton::No | QMessageBox::StandardButton::Yes));
    switch (msgBox->exec()) {
        case QMessageBox::Yes:
            app->Uninstall();
            this->close();
            this->deleteLater();
            break;
        case QMessageBox::No:
        default:
        break;

    }
}

void SettingsWindow::on_launchOptionsField_editingFinished()
{
    std::string newOpt = ui->launchOptionsField->text().toStdString();
    this->app->SetLaunchCommandLine(newOpt);
}
