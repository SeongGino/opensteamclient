//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTFRIENDS_H
#define ICLIENTFRIENDS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "FriendsCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Tells Steam where to place the browser window inside the overlay
//-----------------------------------------------------------------------------
enum EActivateGameOverlayToWebPageMode
{
	k_EActivateGameOverlayToWebPageMode_Default = 0,		// Browser will open next to all other windows that the user has open in the overlay.
															// The window will remain open, even if the user closes then re-opens the overlay.

	k_EActivateGameOverlayToWebPageMode_Modal = 1			// Browser will be opened in a special overlay configuration which hides all other windows
															// that the user has open in the overlay. When the user closes the overlay, the browser window
															// will also close. When the user closes the browser window, the overlay will automatically close.
};


class IClientFriends
{
public:
    virtual const char * GetPersonaName() = 0;
    virtual unknown_ret SetPersonaName(char const*) = 0;
    virtual bool IsPersonaNameSet() = 0;
    virtual EPersonaState GetPersonaState() = 0;
    virtual unknown_ret SetPersonaState(EPersonaState) = 0;
    virtual unknown_ret NotifyUIOfMenuChange(bool, bool, bool, bool) = 0;
    virtual unknown_ret GetFriendCount(int) = 0;
    virtual unknown_ret GetFriendArray(CSteamID*, signed char*, int, int) = 0;
    virtual unknown_ret GetFriendArrayInGame(CSteamID*, unsigned long long*, int) = 0;
    virtual unknown_ret GetFriendByIndex(int, int) = 0;
    virtual unknown_ret GetOnlineFriendCount() = 0;
    virtual unknown_ret GetFriendRelationship(CSteamID) = 0;
    virtual unknown_ret GetFriendPersonaState(CSteamID) = 0;
    virtual unknown_ret GetFriendPersonaName(CSteamID) = 0;
    virtual unknown_ret GetSmallFriendAvatar(CSteamID) = 0;
    virtual unknown_ret GetMediumFriendAvatar(CSteamID) = 0;
    virtual unknown_ret GetLargeFriendAvatar(CSteamID) = 0;
    virtual unknown_ret BGetFriendAvatarURL(char*, unsigned int, CSteamID, int) = 0;
    virtual unknown_ret GetFriendAvatarHash(char*, unsigned int, CSteamID) = 0;
    virtual unknown_ret SetFriendRegValue(CSteamID, char const*, char const*) = 0;
    virtual unknown_ret GetFriendRegValue(CSteamID, char const*) = 0;
    virtual unknown_ret DeleteFriendRegValue(CSteamID, char const*) = 0;
    virtual unknown_ret GetFriendGamePlayed(CSteamID, FriendGameInfo_t*) = 0;
    virtual unknown_ret GetFriendGamePlayedExtraInfo(CSteamID) = 0;
    virtual unknown_ret GetFriendGameServer(CSteamID) = 0;
    virtual unknown_ret GetFriendPersonaStateFlags(CSteamID) = 0;
    virtual unknown_ret GetFriendSessionStateInfo(CSteamID) = 0;
    virtual unknown_ret GetFriendRestrictions(CSteamID) = 0;
    virtual unknown_ret GetFriendBroadcastID(CSteamID) = 0;
    virtual unknown_ret GetFriendPersonaNameHistory(CSteamID, int) = 0;
    virtual unknown_ret RequestPersonaNameHistory(CSteamID) = 0;
    virtual unknown_ret GetFriendPersonaNameHistoryAndDate(CSteamID, int, unsigned int*) = 0;
    virtual unknown_ret AddFriend(CSteamID) = 0;
    virtual unknown_ret RemoveFriend(CSteamID) = 0;
    virtual unknown_ret HasFriend(CSteamID, int) = 0;
    virtual unknown_ret RequestUserInformation(CSteamID, bool) = 0;
    virtual unknown_ret SetIgnoreFriend(CSteamID, bool) = 0;
    virtual unknown_ret ReportChatDeclined(CSteamID) = 0;
    virtual unknown_ret CreateFriendsGroup(char const*) = 0;
    virtual unknown_ret DeleteFriendsGroup(short) = 0;
    virtual unknown_ret RenameFriendsGroup(char const*, short) = 0;
    virtual unknown_ret AddFriendToGroup(CSteamID, short) = 0;
    virtual unknown_ret RemoveFriendFromGroup(CSteamID, short) = 0;
    virtual unknown_ret IsFriendMemberOfFriendsGroup(CSteamID, short) = 0;
    virtual unknown_ret GetFriendsGroupCount() = 0;
    virtual unknown_ret GetFriendsGroupIDByIndex(short) = 0;
    virtual unknown_ret GetFriendsGroupName(short) = 0;
    virtual unknown_ret GetFriendsGroupMembershipCount(short) = 0;
    virtual unknown_ret GetFirstFriendsGroupMember(short) = 0;
    virtual unknown_ret GetNextFriendsGroupMember(short) = 0;
    virtual unknown_ret GetGroupFriendsMembershipCount(CSteamID) = 0;
    virtual unknown_ret GetFirstGroupFriendsMember(CSteamID) = 0;
    virtual unknown_ret GetNextGroupFriendsMember(CSteamID) = 0;
    virtual unknown_ret GetPlayerNickname(CSteamID) = 0;
    virtual unknown_ret SetPlayerNickname(CSteamID, char const*) = 0;
    virtual unknown_ret GetFriendSteamLevel(CSteamID) = 0;
    virtual unknown_ret GetChatMessagesCount(CSteamID) = 0;
    virtual unknown_ret GetChatMessage(CSteamID, int, void*, int, EChatEntryType*, unsigned long long*, unsigned int*) = 0;
    virtual unknown_ret SendMsgToFriend(CSteamID, EChatEntryType, char const*) = 0;
    virtual unknown_ret ClearChatHistory(CSteamID) = 0;
    virtual unknown_ret GetKnownClanCount() = 0;
    virtual unknown_ret GetKnownClanByIndex(int) = 0;
    virtual unknown_ret GetClanCount() = 0;
    virtual unknown_ret GetClanByIndex(int) = 0;
    virtual unknown_ret GetClanName(CSteamID) = 0;
    virtual unknown_ret GetClanTag(CSteamID) = 0;
    virtual unknown_ret GetFriendActivityCounts(int*, int*, bool) = 0;
    virtual unknown_ret GetClanActivityCounts(CSteamID, int*, int*, int*) = 0;
    virtual unknown_ret DownloadClanActivityCounts(CSteamID*, int) = 0;
    virtual unknown_ret GetFriendsGroupActivityCounts(short, int*, int*) = 0;
    virtual unknown_ret IsClanPublic(CSteamID) = 0;
    virtual unknown_ret IsClanOfficialGameGroup(CSteamID) = 0;
    virtual unknown_ret JoinClanChatRoom(CSteamID) = 0;
    virtual unknown_ret LeaveClanChatRoom(CSteamID) = 0;
    virtual unknown_ret GetClanChatMemberCount(CSteamID) = 0;
    virtual unknown_ret GetChatMemberByIndex(CSteamID, int) = 0;
    virtual unknown_ret SendClanChatMessage(CSteamID, char const*) = 0;
    virtual unknown_ret GetClanChatMessage(CSteamID, int, void*, int, EChatEntryType*, CSteamID*) = 0;
    virtual unknown_ret IsClanChatAdmin(CSteamID, CSteamID) = 0;
    virtual unknown_ret IsClanChatWindowOpenInSteam(CSteamID) = 0;
    virtual unknown_ret OpenClanChatWindowInSteam(CSteamID) = 0;
    virtual unknown_ret CloseClanChatWindowInSteam(CSteamID) = 0;
    virtual unknown_ret SetListenForFriendsMessages(bool) = 0;
    virtual unknown_ret ReplyToFriendMessage(CSteamID, char const*) = 0;
    virtual unknown_ret GetFriendMessage(CSteamID, int, void*, int, EChatEntryType*) = 0;
    virtual unknown_ret InviteFriendToClan(CSteamID, CSteamID) = 0;
    virtual unknown_ret AcknowledgeInviteToClan(CSteamID, bool) = 0;
    virtual unknown_ret GetFriendCountFromSource(CSteamID) = 0;
    virtual unknown_ret GetFriendFromSourceByIndex(CSteamID, int) = 0;
    virtual unknown_ret IsUserInSource(CSteamID, CSteamID) = 0;
    virtual unknown_ret GetCoplayFriendCount() = 0;
    virtual unknown_ret GetCoplayFriend(int) = 0;
    virtual unknown_ret GetFriendCoplayTime(CSteamID) = 0;
    virtual unknown_ret GetFriendCoplayGame(CSteamID) = 0;
    virtual unknown_ret SetRichPresence(unsigned int, char const*, char const*) = 0;
    virtual unknown_ret ClearRichPresence(unsigned int) = 0;
    virtual unknown_ret GetFriendRichPresence(unsigned int, CSteamID, char const*) = 0;
    virtual unknown_ret GetFriendRichPresenceKeyCount(unsigned int, CSteamID) = 0;
    virtual unknown_ret GetFriendRichPresenceKeyByIndex(unsigned int, CSteamID, int) = 0;
    virtual unknown_ret RequestFriendRichPresence(unsigned int, CSteamID) = 0;
    virtual unknown_ret JoinChatRoom(CSteamID) = 0;
    virtual unknown_ret LeaveChatRoom(CSteamID) = 0;
    virtual unknown_ret InviteUserToChatRoom(CSteamID, CSteamID) = 0;
    virtual unknown_ret SendChatMsg(CSteamID, EChatEntryType, char const*) = 0;
    virtual unknown_ret GetChatRoomMessagesCount(CSteamID) = 0;
    virtual unknown_ret GetChatRoomEntry(CSteamID, int, CSteamID*, void*, int, EChatEntryType*) = 0;
    virtual unknown_ret ClearChatRoomHistory(CSteamID) = 0;
    virtual unknown_ret SerializeChatRoomDlg(CSteamID, void const*, int) = 0;
    virtual unknown_ret GetSizeOfSerializedChatRoomDlg(CSteamID) = 0;
    virtual unknown_ret GetSerializedChatRoomDlg(CSteamID, void*, int, int*, EChatRoomType*) = 0;
    virtual unknown_ret ClearSerializedChatRoomDlg(CSteamID) = 0;
    virtual unknown_ret KickChatMember(CSteamID, CSteamID) = 0;
    virtual unknown_ret BanChatMember(CSteamID, CSteamID) = 0;
    virtual unknown_ret UnBanChatMember(CSteamID, CSteamID) = 0;
    virtual unknown_ret SetChatRoomType(CSteamID, ELobbyType) = 0;
    virtual unknown_ret GetChatRoomLockState(CSteamID, bool*) = 0;
    virtual unknown_ret GetChatRoomPermissions(CSteamID, unsigned int*) = 0;
    virtual unknown_ret SetChatRoomModerated(CSteamID, bool) = 0;
    virtual unknown_ret BChatRoomModerated(CSteamID) = 0;
    virtual unknown_ret NotifyChatRoomDlgsOfUIChange(CSteamID, bool, bool, bool, bool) = 0;
    virtual unknown_ret TerminateChatRoom(CSteamID) = 0;
    virtual unknown_ret GetChatRoomCount() = 0;
    virtual unknown_ret GetChatRoomByIndex(int) = 0;
    virtual unknown_ret GetChatRoomName(CSteamID) = 0;
    virtual unknown_ret BGetChatRoomMemberDetails(CSteamID, CSteamID, unsigned int*, unsigned int*) = 0;
    virtual unknown_ret CreateChatRoom(EChatRoomType, unsigned long long, char const*, ELobbyType, CSteamID, CSteamID, CSteamID, unsigned int, unsigned int, unsigned int) = 0;
    virtual unknown_ret JoinChatRoomGroup(unsigned long long, unsigned long long) = 0;
    virtual unknown_ret ShowChatRoomGroupInvite(char const*) = 0;
    virtual unknown_ret VoiceCallNew(CSteamID, CSteamID) = 0;
    virtual unknown_ret VoiceCall(CSteamID, CSteamID) = 0;
    virtual unknown_ret VoiceHangUp(CSteamID, int) = 0;
    virtual unknown_ret SetVoiceSpeakerVolume(float) = 0;
    virtual unknown_ret SetVoiceMicrophoneVolume(float) = 0;
    virtual unknown_ret SetAutoAnswer(bool) = 0;
    virtual unknown_ret VoiceAnswer(int) = 0;
    virtual unknown_ret AcceptVoiceCall(CSteamID, CSteamID) = 0;
    virtual unknown_ret VoicePutOnHold(int, bool) = 0;
    virtual unknown_ret BVoiceIsLocalOnHold(int) = 0;
    virtual unknown_ret BVoiceIsRemoteOnHold(int) = 0;
    virtual unknown_ret SetDoNotDisturb(bool) = 0;
    virtual unknown_ret EnableVoiceNotificationSounds(bool) = 0;
    virtual unknown_ret SetPushToTalkEnabled(bool, bool) = 0;
    virtual unknown_ret IsPushToTalkEnabled() = 0;
    virtual unknown_ret IsPushToMuteEnabled() = 0;
    virtual unknown_ret SetPushToTalkKey(int) = 0;
    virtual unknown_ret GetPushToTalkKey() = 0;
    virtual unknown_ret IsPushToTalkKeyDown() = 0;
    virtual unknown_ret EnableVoiceCalibration(bool) = 0;
    virtual unknown_ret IsVoiceCalibrating() = 0;
    virtual unknown_ret GetVoiceCalibrationSamplePeak() = 0;
    virtual unknown_ret SetMicBoost(bool) = 0;
    virtual unknown_ret GetMicBoost() = 0;
    virtual unknown_ret HasHardwareMicBoost() = 0;
    virtual unknown_ret GetMicDeviceName() = 0;
    virtual unknown_ret StartTalking(int) = 0;
    virtual unknown_ret EndTalking(int) = 0;
    virtual unknown_ret VoiceIsValid(int) = 0;
    virtual unknown_ret SetAutoReflectVoice(bool) = 0;
    virtual unknown_ret GetCallState(int) = 0;
    virtual unknown_ret GetVoiceMicrophoneVolume() = 0;
    virtual unknown_ret GetVoiceSpeakerVolume() = 0;
    virtual unknown_ret TimeSinceLastVoiceDataReceived(int) = 0;
    virtual unknown_ret TimeSinceLastVoiceDataSend(int) = 0;
    virtual unknown_ret BCanSend(int) = 0;
    virtual unknown_ret BCanReceive(int) = 0;
    virtual unknown_ret GetEstimatedBitsPerSecond(int, bool) = 0;
    virtual unknown_ret GetPeakSample(int, bool) = 0;
    virtual unknown_ret SendResumeRequest(int) = 0;
    virtual unknown_ret OpenFriendsDialog(bool, bool) = 0;
    virtual unknown_ret OpenChatDialog(CSteamID) = 0;
    virtual unknown_ret OpenInviteToTradeDialog(CSteamID) = 0;
    virtual unknown_ret StartChatRoomVoiceSpeaking(CSteamID, CSteamID) = 0;
    virtual unknown_ret EndChatRoomVoiceSpeaking(CSteamID, CSteamID) = 0;
    virtual unknown_ret GetFriendLastLogonTime(CSteamID) = 0;
    virtual unknown_ret GetFriendLastLogoffTime(CSteamID) = 0;
    virtual unknown_ret GetChatRoomVoiceTotalSlotCount(CSteamID) = 0;
    virtual unknown_ret GetChatRoomVoiceUsedSlotCount(CSteamID) = 0;
    virtual unknown_ret GetChatRoomVoiceUsedSlot(CSteamID, int) = 0;
    virtual unknown_ret GetChatRoomVoiceStatus(CSteamID, CSteamID) = 0;
    virtual unknown_ret BChatRoomHasAvailableVoiceSlots(CSteamID) = 0;
    virtual unknown_ret BIsChatRoomVoiceSpeaking(CSteamID, CSteamID) = 0;
    virtual unknown_ret GetChatRoomPeakSample(CSteamID, CSteamID, bool) = 0;
    virtual unknown_ret ChatRoomVoiceRetryConnections(CSteamID) = 0;
    virtual unknown_ret SetPortTypes(unsigned int) = 0;
    virtual unknown_ret ReinitAudio() = 0;
    virtual unknown_ret SetInGameVoiceSpeaking(CSteamID, bool) = 0;
    virtual unknown_ret IsInGameVoiceSpeaking() = 0;
    virtual unknown_ret ActivateGameOverlay(char const*) = 0;
    virtual unknown_ret ActivateGameOverlayToUser(char const*, CSteamID) = 0;
    virtual unknown_ret ActivateGameOverlayToWebPage(char const*, EActivateGameOverlayToWebPageMode) = 0;
    virtual unknown_ret ActivateGameOverlayToStore(unsigned int, EOverlayToStoreFlag) = 0;
    virtual unknown_ret ActivateGameOverlayInviteDialog(CSteamID) = 0;
    virtual unknown_ret ActivateGameOverlayRemotePlayTogetherInviteDialog(CSteamID) = 0;
    virtual unknown_ret ActivateGameOverlayInviteDialogConnectString(char const*) = 0;
    virtual unknown_ret ProcessActivateGameOverlayInMainUI(char const*, CSteamID, unsigned int, bool, int) = 0;
    virtual unknown_ret NotifyGameOverlayStateChanged(bool) = 0;
    virtual unknown_ret NotifyGameServerChangeRequested(char const*, char const*) = 0;
    virtual unknown_ret NotifyLobbyJoinRequested(unsigned int, CSteamID, CSteamID) = 0;
    virtual unknown_ret NotifyRichPresenceJoinRequested(unsigned int, CSteamID, char const*) = 0;
    virtual unknown_ret GetClanRelationship(CSteamID) = 0;
    virtual unknown_ret GetClanInviteCount() = 0;
    virtual unknown_ret GetFriendClanRank(CSteamID, CSteamID) = 0;
    virtual unknown_ret VoiceIsAvailable() = 0;
    virtual unknown_ret TestVoiceDisconnect(int) = 0;
    virtual unknown_ret TestChatRoomPeerDisconnect(CSteamID, CSteamID) = 0;
    virtual unknown_ret TestVoicePacketLoss(float) = 0;
    virtual unknown_ret FindFriendVoiceChatHandle(CSteamID) = 0;
    virtual unknown_ret RequestFriendsWhoPlayGame(CGameID) = 0;
    virtual unknown_ret GetCountFriendsWhoPlayGame(CGameID) = 0;
    virtual unknown_ret GetFriendWhoPlaysGame(unsigned int, CGameID) = 0;
    virtual unknown_ret GetCountFriendsInGame(CGameID) = 0;
    virtual unknown_ret SetPlayedWith(CSteamID) = 0;
    virtual unknown_ret RequestClanOfficerList(CSteamID) = 0;
    virtual unknown_ret GetClanOwner(CSteamID) = 0;
    virtual unknown_ret GetClanOfficerCount(CSteamID) = 0;
    virtual unknown_ret GetClanOfficerByIndex(CSteamID, int) = 0;
    virtual unknown_ret GetUserRestrictions() = 0;
    virtual unknown_ret RequestFriendProfileInfo(CSteamID) = 0;
    virtual unknown_ret GetFriendProfileInfo(CSteamID, char const*) = 0;
    virtual unknown_ret InviteUserToGame(unsigned int, CSteamID, char const*) = 0;
    virtual unknown_ret GetOnlineConsoleFriendCount() = 0;
    virtual unknown_ret RequestTrade(CSteamID) = 0;
    virtual unknown_ret TradeResponse(unsigned int, bool) = 0;
    virtual unknown_ret CancelTradeRequest(CSteamID) = 0;
    virtual unknown_ret HideFriend(CSteamID, bool) = 0;
    virtual unknown_ret GetFollowerCount(CSteamID) = 0;
    virtual unknown_ret IsFollowing(CSteamID) = 0;
    virtual unknown_ret EnumerateFollowingList(unsigned int) = 0;
    virtual unknown_ret RequestFriendMessageHistory(CSteamID) = 0;
    virtual unknown_ret RequestFriendMessageHistoryForOfflineMessages() = 0;
    virtual unknown_ret GetCountFriendsWithOfflineMessages() = 0;
    virtual unknown_ret GetFriendWithOfflineMessage(int) = 0;
    virtual unknown_ret ClearFriendHasOfflineMessage(unsigned int) = 0;
    virtual unknown_ret RequestEmoticonList() = 0;
    virtual unknown_ret GetEmoticonCount() = 0;
    virtual unknown_ret GetEmoticonName(int) = 0;
    virtual unknown_ret ClientLinkFilterInit() = 0;
    virtual unknown_ret LinkDisposition(char const*) = 0;
    virtual unknown_ret GetFriendPersonaName_Public(CSteamID) = 0;
    virtual unknown_ret GetPlayerNickname_Public(CSteamID) = 0;
    virtual unknown_ret SetFriendsUIActiveClanChatList(unsigned int*, int) = 0;
    virtual unknown_ret GetNumChatsWithUnreadPriorityMessages() = 0;
    virtual unknown_ret SetNumChatsWithUnreadPriorityMessages(int) = 0;
    virtual unknown_ret RegisterProtocolInOverlayBrowser(char const*) = 0;
    virtual unknown_ret HandleProtocolForOverlayBrowser(unsigned int, char const*) = 0;
};

#endif // ICLIENTFRIENDS_H
