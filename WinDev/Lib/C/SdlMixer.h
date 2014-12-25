/*  Ofront 1.2 -xtspkae */

#ifndef SdlMixer__h
#define SdlMixer__h

#include "SYSTEM.h"
#include "SdlLib.h"

typedef
	struct SdlMixer_Mix_Chunk {
		INTEGER allocated;
		SYSTEM_PTR abuf;
		INTEGER alen;
		CHAR volume;
	} SdlMixer_Mix_Chunk;

typedef
	struct SdlMixer_MusicUnion {
		char _prvt0[1];
	} SdlMixer_MusicUnion;

typedef
	struct SdlMixer_Mix_Music {
		BYTE type;
		SdlMixer_MusicUnion data;
		BYTE fading;
		INTEGER fade_volume, fade_step, fade_steps, error;
	} SdlMixer_Mix_Music;

typedef
	SdlMixer_Mix_Chunk *SdlMixer_PMix_Chunk;

typedef
	SdlMixer_Mix_Music *SdlMixer_PMix_Music;



import LONGINT *SdlMixer_Mix_Chunk__typ;
import LONGINT *SdlMixer_MusicUnion__typ;
import LONGINT *SdlMixer_Mix_Music__typ;

import void *SdlMixer__init(void);

#define SdlMixer_Mix_AllocateChannels(numchannels)	Mix_AllocateChannels(numchannels)
__EXTERN INTEGER Mix_AllocateChannels(INTEGER numchannels);
#define SdlMixer_Mix_CloseAudio()	Mix_CloseAudio()
__EXTERN void Mix_CloseAudio(void);
#define SdlMixer_Mix_ExpireChannel(channel, ticks)	Mix_ExpireChannel(channel, ticks)
__EXTERN INTEGER Mix_ExpireChannel(INTEGER channel, INTEGER ticks);
#define SdlMixer_Mix_FadeInChannel(channel, chunk, loops, ms)	Mix_FadeInChannelTimed(channel, chunk, loops, ms, -1)
#define SdlMixer_Mix_FadeInChannelTimed(channel, chunk, loops, ms, ticks)	Mix_FadeInChannelTimed(channel, chunk, loops, ms, ticks)
__EXTERN INTEGER Mix_FadeInChannelTimed(INTEGER channel, SdlMixer_PMix_Chunk chunk, INTEGER loops, INTEGER ms, INTEGER ticks);
#define SdlMixer_Mix_FadeInMusic(music, loops, ms)	Mix_FadeInMusic(music, loops, ms)
__EXTERN INTEGER Mix_FadeInMusic(SdlMixer_PMix_Music music, INTEGER loops, INTEGER ms);
#define SdlMixer_Mix_FadeOutChannel(which, ms)	Mix_FadeOutChannel(which, ms)
__EXTERN INTEGER Mix_FadeOutChannel(INTEGER which, INTEGER ms);
#define SdlMixer_Mix_FadeOutGroup(tag, ms)	Mix_FadeOutGroup(tag, ms)
__EXTERN INTEGER Mix_FadeOutGroup(INTEGER tag, INTEGER ms);
#define SdlMixer_Mix_FadeOutMusic(ms)	Mix_FadeOutMusic(ms)
__EXTERN INTEGER Mix_FadeOutMusic(INTEGER ms);
#define SdlMixer_Mix_FadingChannel(which)	Mix_FadingChannel(which)
__EXTERN BYTE Mix_FadingChannel(INTEGER which);
#define SdlMixer_Mix_FadingMusic()	Mix_FadingMusic()
__EXTERN BYTE Mix_FadingMusic(void);
#define SdlMixer_Mix_FreeChunk(chunk)	Mix_FreeChunk(chunk)
__EXTERN void Mix_FreeChunk(SdlMixer_PMix_Chunk chunk);
#define SdlMixer_Mix_FreeMusic(music)	Mix_FreeMusic(music)
__EXTERN void Mix_FreeMusic(SdlMixer_PMix_Music music);
#define SdlMixer_Mix_GetError()	SDL_GetError()
#define SdlMixer_Mix_GetMusicType(music)	Mix_GetMusicType(music)
__EXTERN BYTE Mix_GetMusicType(SdlMixer_PMix_Music music);
#define SdlMixer_Mix_GroupAvailable(tag)	Mix_GroupAvailable(tag)
__EXTERN INTEGER Mix_GroupAvailable(INTEGER tag);
#define SdlMixer_Mix_GroupChannel(which, tag)	Mix_GroupChannel(which, tag)
__EXTERN INTEGER Mix_GroupChannel(INTEGER which, INTEGER tag);
#define SdlMixer_Mix_GroupChannels(from, to, tag)	Mix_GroupChannels(from, to, tag)
__EXTERN INTEGER Mix_GroupChannels(INTEGER from, INTEGER to, INTEGER tag);
#define SdlMixer_Mix_GroupCount(tag)	Mix_GroupCount(tag)
__EXTERN INTEGER Mix_GroupCount(INTEGER tag);
#define SdlMixer_Mix_GroupNewer(tag)	Mix_GroupNewer(tag)
__EXTERN INTEGER Mix_GroupNewer(INTEGER tag);
#define SdlMixer_Mix_GroupOldest(tag)	Mix_GroupOldest(tag)
__EXTERN INTEGER Mix_GroupOldest(INTEGER tag);
#define SdlMixer_Mix_HaltChannel(channel)	Mix_HaltChannel(channel)
__EXTERN INTEGER Mix_HaltChannel(INTEGER channel);
#define SdlMixer_Mix_HaltGroup(tag)	Mix_HaltGroup(tag)
__EXTERN INTEGER Mix_HaltGroup(INTEGER tag);
#define SdlMixer_Mix_HaltMusic()	Mix_HaltMusic()
__EXTERN INTEGER Mix_HaltMusic(void);
#define SdlMixer_Mix_LoadMUS(file)	Mix_LoadMUS(file)
__EXTERN SdlMixer_PMix_Music Mix_LoadMUS(SYSTEM_PTR file);
#define SdlMixer_Mix_LoadMUS_RW(rw)	Mix_LoadMUS_RW(rw)
__EXTERN SdlMixer_PMix_Music Mix_LoadMUS_RW(SdlLib_PRWops rw);
#define SdlMixer_Mix_LoadWAV(file)	Mix_LoadWAV_RW(SDL_RWFromFile((SYSTEM_PTR)file, (SYSTEM_PTR)"rb"), 1)
#define SdlMixer_Mix_LoadWAV_RW(src, freesrc)	Mix_LoadWAV_RW(src, freesrc)
__EXTERN SdlMixer_PMix_Chunk Mix_LoadWAV_RW(SdlLib_PRWops src, INTEGER freesrc);
#define SdlMixer_Mix_OpenAudio(frequency, format, channels, chunksize)	Mix_OpenAudio(frequency, format, channels, chunksize)
__EXTERN INTEGER Mix_OpenAudio(INTEGER frequency, SHORTINT format, INTEGER channels, INTEGER chunksize);
#define SdlMixer_Mix_Pause(channel)	Mix_Pause(channel)
__EXTERN void Mix_Pause(INTEGER channel);
#define SdlMixer_Mix_PauseMusic()	Mix_PauseMusic()
__EXTERN void Mix_PauseMusic(void);
#define SdlMixer_Mix_Paused(channel)	Mix_Paused(channel)
__EXTERN INTEGER Mix_Paused(INTEGER channel);
#define SdlMixer_Mix_PausedMusic()	Mix_PausedMusic()
__EXTERN INTEGER Mix_PausedMusic(void);
#define SdlMixer_Mix_PlayChannel(channel, chunk, loops)	Mix_PlayChannelTimed(channel, chunk, loops, -1)
#define SdlMixer_Mix_PlayChannelTimed(channel, chunk, loops, ticks)	Mix_PlayChannelTimed(channel, chunk, loops, ticks)
__EXTERN INTEGER Mix_PlayChannelTimed(INTEGER channel, SdlMixer_PMix_Chunk chunk, INTEGER loops, INTEGER ticks);
#define SdlMixer_Mix_PlayMusic(music, loops)	Mix_PlayMusic(music, loops)
__EXTERN INTEGER Mix_PlayMusic(SdlMixer_PMix_Music music, INTEGER loops);
#define SdlMixer_Mix_Playing(channel)	Mix_Playing(channel)
__EXTERN INTEGER Mix_Playing(INTEGER channel);
#define SdlMixer_Mix_PlayingMusic()	Mix_PlayingMusic()
__EXTERN INTEGER Mix_PlayingMusic(void);
#define SdlMixer_Mix_QuerySpec(frequency, format, channels)	Mix_QuerySpec(frequency, format, channels)
__EXTERN INTEGER Mix_QuerySpec(INTEGER *frequency, SHORTINT *format, INTEGER *channels);
#define SdlMixer_Mix_QuickLoad_WAV(mem)	Mix_QuickLoad_WAV(mem)
__EXTERN SdlMixer_PMix_Chunk Mix_QuickLoad_WAV(SYSTEM_PTR mem);
#define SdlMixer_Mix_ReserveChannels(num)	Mix_ReserveChannels(num)
__EXTERN INTEGER Mix_ReserveChannels(INTEGER num);
#define SdlMixer_Mix_Resume(channel)	Mix_Resume(channel)
__EXTERN void Mix_Resume(INTEGER channel);
#define SdlMixer_Mix_ResumeMusic()	Mix_ResumeMusic()
__EXTERN void Mix_ResumeMusic(void);
#define SdlMixer_Mix_RewindMusic()	Mix_RewindMusic()
__EXTERN void Mix_RewindMusic(void);
#define SdlMixer_Mix_SetDistance(channel, distance)	Mix_SetDistance(channel, distance)
__EXTERN INTEGER Mix_SetDistance(INTEGER channel, CHAR distance);
#define SdlMixer_Mix_SetError(fmt)	SDL_SetError(fmt)
#define SdlMixer_Mix_SetMusicCMD(command)	Mix_SetMusicCMD(command)
__EXTERN INTEGER Mix_SetMusicCMD(SYSTEM_PTR command);
#define SdlMixer_Mix_SetMusicPosition(position)	Mix_SetMusicPosition(position)
__EXTERN INTEGER Mix_SetMusicPosition(LONGREAL position);
#define SdlMixer_Mix_SetPanning(channel, left, right)	Mix_SetPanning(channel, left, right)
__EXTERN INTEGER Mix_SetPanning(INTEGER channel, CHAR left, CHAR right);
#define SdlMixer_Mix_SetPosition(channel, angle, distance)	Mix_SetPosition(channel, angle, distance)
__EXTERN INTEGER Mix_SetPosition(INTEGER channel, SHORTINT angle, CHAR distance);
#define SdlMixer_Mix_SetReverseStereo(channel, flip)	Mix_SetReverseStereo(channel, flip)
__EXTERN INTEGER Mix_SetReverseStereo(INTEGER channel, INTEGER flip);
#define SdlMixer_Mix_Volume(channel, volume)	Mix_Volume(channel, volume)
__EXTERN INTEGER Mix_Volume(INTEGER channel, INTEGER volume);
#define SdlMixer_Mix_VolumeChunk(chunk, volume)	Mix_VolumeChunk(chunk, volume)
__EXTERN INTEGER Mix_VolumeChunk(SdlMixer_PMix_Chunk chunk, INTEGER volume);
#define SdlMixer_Mix_VolumeMusic(volume)	Mix_VolumeMusic(volume)
__EXTERN INTEGER Mix_VolumeMusic(INTEGER volume);
#define SdlMixer__init()	/*-noinit*/

#endif
