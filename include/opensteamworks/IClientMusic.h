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

#ifndef ICLIENTMUSIC_H
#define ICLIENTMUSIC_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "MusicCommon.h"

enum MediaController_Status
{
	// TODO: Reverse this enum
};

#define CLIENTMUSIC_INTERFACE_VERSION "CLIENTMUSIC_INTERFACE_VERSION001"

abstract_class UNSAFE_INTERFACE IClientMusic
{
public:
	    virtual unknown_ret BIsEnabled() = 0;
    virtual unknown_ret Enable(bool) = 0;
    virtual unknown_ret EnableCrawlLogging(bool) = 0;
    virtual unknown_ret BIsPlaying() = 0;
    virtual unknown_ret GetQueueCount() = 0;
    virtual unknown_ret GetCurrentQueueEntry() = 0;
    virtual unknown_ret GetQueueEntryURI(int, char*, int) = 0;
    virtual unknown_ret GetQueueEntryData(int, char*, int, char*, int, char*, int, int*, void*, int*) = 0;
    virtual unknown_ret GetQueueEntryOrigin(int, void*, int*) = 0;
    virtual unknown_ret EmptyQueue() = 0;
    virtual unknown_ret RemoveQueueEntry(int, bool) = 0;
    virtual unknown_ret AddArtistToQueue(char const*, bool, bool) = 0;
    virtual unknown_ret AddTracksOfAlbumIDToQueue(int, int, bool, char const*, bool, bool, bool) = 0;
    virtual unknown_ret AddAllTracksOfAlbumIDToQueue(int, int, bool, bool, bool) = 0;
    virtual unknown_ret AddTracksOfPlaylistIDToQueue(int, int, bool, bool, bool, bool) = 0;
    virtual unknown_ret SetSuppressAutoTrackAdvance(bool) = 0;
    virtual unknown_ret GetPlaybackStatus() = 0;
    virtual unknown_ret SetPlayingRepeatStatus(void) = 0;
    virtual unknown_ret GetPlayingRepeatStatus() = 0;
    virtual unknown_ret TogglePlayingRepeatStatus() = 0;
    virtual unknown_ret SetPlayingShuffled(bool) = 0;
    virtual unknown_ret IsPlayingShuffled() = 0;
    virtual unknown_ret Play() = 0;
    virtual unknown_ret Pause() = 0;
    virtual unknown_ret PlayPrevious() = 0;
    virtual unknown_ret PlayNext() = 0;
    virtual unknown_ret PlayEntry(int) = 0;
    virtual unknown_ret TogglePlayPause() = 0;
    virtual unknown_ret SetVolume(float) = 0;
    virtual unknown_ret GetVolume() = 0;
    virtual unknown_ret ToggleMuteVolume() = 0;
    virtual unknown_ret IncreaseVolume() = 0;
    virtual unknown_ret DecreaseVolume() = 0;
    virtual unknown_ret SetPlaybackPosition(int) = 0;
    virtual unknown_ret GetPlaybackPosition() = 0;
    virtual unknown_ret GetPlaybackDuration() = 0;
    virtual unknown_ret LocalLibraryCrawlTrack(char const*) = 0;
    virtual unknown_ret ResetLocalLibrary() = 0;
    virtual unknown_ret GetStatusLocalLibrary() = 0;
    virtual unknown_ret SaveLocalLibraryDirectorySettings() = 0;
    virtual unknown_ret GetLocalLibraryDirectoryEntryCount() = 0;
    virtual unknown_ret GetLocalLibraryDirectoryEntry(int, char*, int) = 0;
    virtual unknown_ret AddLocalLibraryDirectoryEntry(char const*) = 0;
    virtual unknown_ret ResetLocalLibraryDirectories(bool) = 0;
    virtual unknown_ret GetDefaultLocalLibraryDirectory(char*, int) = 0;
    virtual unknown_ret LocalLibraryStopCrawling() = 0;
    virtual unknown_ret UpdateLocalLibraryDirectoriesToCrawl() = 0;
    virtual unknown_ret BLocalLibraryIsCrawling() = 0;
    virtual unknown_ret GetLocalLibraryTrackCount() = 0;
    virtual unknown_ret GetLocalLibraryAlbumCount() = 0;
    virtual unknown_ret GetLocalLibraryAlbumID(int, bool) = 0;
    virtual unknown_ret GetLocalLibraryAlbumIDEntry(int, char*, int, char*, int, int*, int*, bool*) = 0;
    virtual unknown_ret GetLocalLibraryAlbumIDTrackEntry(int, int, char*, int, int*, char*, int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryAlbumDirectoryForAlbumID(int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryAlbumSortNameForAlbumID(int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryArtistSortNameForAlbumID(int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryTrackCountForAlbumID(int) = 0;
    virtual unknown_ret GetLocalLibraryAlbumIDTrackKey(int, int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryAlbumIDForTrackKey(char const*) = 0;
    virtual unknown_ret GetLocalLibraryArtistCount() = 0;
    virtual unknown_ret GetLocalLibraryArtistName(int, char*, int, char*, int) = 0;
    virtual unknown_ret GetLocalLibraryAlbumCountForArtistName(char const*) = 0;
    virtual unknown_ret GetLocalLibraryTrackAndAlbumCountOfArtistName(char const*, int*, int*) = 0;
    virtual unknown_ret GetLocalLibraryAlbumIDForArtist(char const*, int) = 0;
    virtual unknown_ret GetLocalLibraryRepresentativeAlbumIDForArtist(char const*, bool*) = 0;
    virtual unknown_ret GetLocalLibraryTrackEntry(char const*, char*, int, int*, char*, int) = 0;
    virtual unknown_ret BRequestAllArtistListData(int) = 0;
    virtual unknown_ret BRequestAllAlbumListData(int) = 0;
    virtual unknown_ret BRequestAllTracksListDataForAlbumID(int, int) = 0;
    virtual unknown_ret GetPlaylistCount() = 0;
    virtual unknown_ret GetPlaylistID(int) = 0;
    virtual unknown_ret GetPositionForPlaylistID(int) = 0;
    virtual unknown_ret GetPlaylistIDForPosition(int) = 0;
    virtual unknown_ret BRequestAllPlayListData(int) = 0;
    virtual unknown_ret GetNextPlaylistName(char const*, char*, int) = 0;
    virtual unknown_ret InsertPlaylistWithNameAtPosition(char const*, int) = 0;
    virtual unknown_ret MovePlaylistFromPositionToPosition(int, int) = 0;
    virtual unknown_ret DeletePlaylistWithID(int) = 0;
    virtual unknown_ret RenamePlaylistWithID(int, char const*) = 0;
    virtual unknown_ret AddRandomTracksToPlaylistID(int, int) = 0;
    virtual unknown_ret GetPlaylistIDData(int, char*, int, int*, int*, int*, int*, int*) = 0;
    virtual unknown_ret GetPlaylistIDTrackCount(int) = 0;
    virtual unknown_ret BRequestAllTracksListDataForPlaylistID(int, int) = 0;
    virtual unknown_ret GetPlaylistIDTrackKey(int, int, char*, int, int*) = 0;
    virtual unknown_ret GetPositionForPlaylistItemID(int) = 0;
    virtual unknown_ret AddTrackKeyToPlaylistID(int, char const*) = 0;
    virtual unknown_ret AddAlbumIDToPlaylistID(int, int, char const*) = 0;
    virtual unknown_ret AddArtistNameToPlaylistID(int, char const*) = 0;
    virtual unknown_ret AddPlaylistIDToPlaylistID(int, int) = 0;
    virtual unknown_ret RemovePlaylistPositionFromPlaylistID(int, int) = 0;
    virtual unknown_ret RemoveAllTracksFromPlaylistID(int, bool) = 0;
    virtual unknown_ret MoveTrackFromPositionToPositonInPlaylistID(int, int, int) = 0;
    virtual unknown_ret AppendQueueToPlaylistID(int, bool) = 0;
    virtual unknown_ret GetLocalLibraryRepresentativeAlbumIDForPlaylist(int, bool*) = 0;
    virtual unknown_ret MarkTrackKeyAsPlayed(char const*) = 0;
    virtual unknown_ret GetMostRecentlyPlayedAlbums(int, int*) = 0;
    virtual unknown_ret GetMostRecentlyAddedAlbums(int, int*) = 0;
    virtual unknown_ret ActivateRemotePlayerWithID(int) = 0;
    virtual unknown_ret GetActiveRemotePlayerID() = 0;
    virtual unknown_ret GetRemotePlayerCount() = 0;
    virtual unknown_ret GetRemotePlayerIDAndName(int, int*, char*, int) = 0;
    virtual unknown_ret GetCurrentEntryTextForRemotePlayerWithID(int, char*, int) = 0;
    virtual unknown_ret RegisterSteamMusicRemote(char const*) = 0;
    virtual unknown_ret DeregisterSteamMusicRemote() = 0;
    virtual unknown_ret BIsCurrentMusicRemote() = 0;
    virtual unknown_ret BActivationSuccess(bool) = 0;
    virtual unknown_ret SetDisplayName(char const*) = 0;
    virtual unknown_ret SetPNGIcon_64x64(void*, unsigned int) = 0;
    virtual unknown_ret EnablePlayPrevious(bool) = 0;
    virtual unknown_ret EnablePlayNext(bool) = 0;
    virtual unknown_ret EnableShuffled(bool) = 0;
    virtual unknown_ret EnableLooped(bool) = 0;
    virtual unknown_ret EnableQueue(bool) = 0;
    virtual unknown_ret EnablePlaylists(bool) = 0;
    virtual unknown_ret UpdatePlaybackStatus(AudioPlayback_Status) = 0;
    virtual unknown_ret UpdateShuffled(bool) = 0;
    virtual unknown_ret UpdateLooped(bool) = 0;
    virtual unknown_ret UpdateVolume(float) = 0;
    virtual unknown_ret CurrentEntryWillChange() = 0;
    virtual unknown_ret CurrentEntryIsAvailable(bool) = 0;
    virtual unknown_ret UpdateCurrentEntryText(char const*) = 0;
    virtual unknown_ret UpdateCurrentEntryElapsedSeconds(int) = 0;
    virtual unknown_ret UpdateCurrentEntryCoverArt(void*, unsigned int) = 0;
    virtual unknown_ret CurrentEntryDidChange() = 0;
    virtual unknown_ret QueueWillChange() = 0;
    virtual unknown_ret ResetQueueEntries() = 0;
    virtual unknown_ret SetQueueEntry(int, int, char const*) = 0;
    virtual unknown_ret SetCurrentQueueEntry(int) = 0;
    virtual unknown_ret QueueDidChange() = 0;
    virtual unknown_ret PlaylistWillChange() = 0;
    virtual unknown_ret ResetPlaylistEntries() = 0;
    virtual unknown_ret SetPlaylistEntry(int, int, char const*) = 0;
    virtual unknown_ret SetCurrentPlaylistEntry(int) = 0;
    virtual unknown_ret PlaylistDidChange() = 0;
    virtual unknown_ret RequestAlbumCoverForAlbumID(int) = 0;
    virtual unknown_ret RequestAlbumCoverForTrackKey(char const*) = 0;
    virtual unknown_ret GetAlbumCoverForIndex(int, void*, unsigned int) = 0;
    virtual unknown_ret CancelAlbumCoverRequestForIndex(int) = 0;
    virtual unknown_ret GetAlbumCoverURLForAlbumID(int, char*, unsigned int) = 0;
    virtual unknown_ret GetAlbumCoverURLForTrackKey(char const*, char*, unsigned int) = 0;
    virtual unknown_ret StartUsingSpotify() = 0;
    virtual unknown_ret StopUsingSpotify() = 0;
    virtual unknown_ret GetStatusSpotify() = 0;
    virtual unknown_ret LoginSpotify(char const*, char const*) = 0;
    virtual unknown_ret ReloginSpotify() = 0;
    virtual unknown_ret GetCurrentUserSpotify() = 0;
    virtual unknown_ret ForgetCurrentUserSpotify() = 0;
    virtual unknown_ret LogoutSpotify() = 0;
    virtual unknown_ret DumpStatusToConsole() = 0;
    virtual unknown_ret ReplacePlaylistWithSoundtrackAlbum(unsigned int) = 0;
};

#endif // ICLIENTMUSIC_H
