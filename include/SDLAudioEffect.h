#pragma once

#include "Audio.h"

class SDLAudioEffect : public Audio
{
public:
	SDLAudioEffect(ResourceLoader *loader, const std::string &path)
		:Audio(loader, path)
		, m_effect(nullptr)
	{}
	virtual ~SDLAudioEffect();

	virtual bool Init() override { return false; }
	virtual bool Load() override;
	virtual bool Play(int numloop) override;

protected:
	struct Mix_Chunk *m_effect;
};