#include "SDLAudioMusic.h"

bool SDLAudioMusic::Load()
{
	m_music = Mix_LoadMUS(m_path.c_str());

	return true;
}

bool SDLAudioMusic::Play(int numloop)
{
	return Mix_PlayMusic(m_music, numloop);
}

SDLAudioMusic::~SDLAudioMusic()
{
	if (m_music)
	{
		Mix_FreeMusic(m_music);
		m_music = nullptr;
	}
}
