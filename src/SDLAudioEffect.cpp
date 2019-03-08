#include "SDLAudioEffect.h"
#include <SDL_mixer.h>

bool SDLAudioEffect::Load()
{
	m_effect = Mix_LoadWAV(m_path.c_str());
	return true;
}

bool SDLAudioEffect::Play(int numloop)
{
	return Mix_PlayChannel(-1, m_effect, numloop);
}

SDLAudioEffect::~SDLAudioEffect()
{
	if (m_effect)
	{
		Mix_FreeChunk(m_effect);
		m_effect = nullptr;
	}
}