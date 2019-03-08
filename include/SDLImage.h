#pragma once

#include "Image.h"

class Application;
class SDL_Texture;
class SDLView;
class SDLGraphics;
struct SDL_Surface;

class SDLImage : public Image
{
public:
	SDLImage(ResourceLoader *loader, SDLGraphics* graphics, const std::string &path);
	virtual ~SDLImage() {}

	virtual bool Load() override;
	virtual bool Init() override;

	virtual int getWidth() override;
	virtual int getHeight() override;

	SDL_Texture* GetTexture();
private:
	int			m_width;
	int			m_height;
	SDLGraphics	*m_graphics;
	SDL_Texture	*m_texture;
	SDL_Surface *m_imageSurface;
	Application *m_app;
};