#pragma once

#include "Audio.h"
#include <SDL_mixer.h>

class SDLAudioMusic : public Audio
{
public:
	SDLAudioMusic(ResourceLoader *loader, const std::string &path)
		: Audio(loader, path)
		, m_music(nullptr)
	{
	}
	virtual ~SDLAudioMusic();

	virtual bool Init() override { return false; }
	virtual bool Load() override;
	virtual bool Play(int numloop) override;

protected:
	Mix_Music *m_music;
};