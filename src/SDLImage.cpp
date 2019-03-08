#include "SDLImage.h"
#include <SDL_image.h>
#include "SDLView.h"
#include "SDLGraphics.h"

SDLImage::SDLImage(ResourceLoader *loader, SDLGraphics* graphics, const std::string &path)
	: Image(loader,path)
	, m_width(-1)
	, m_height(-1)
	, m_texture(nullptr)
	, m_graphics(graphics)
{
	
}

bool SDLImage::Load()
{
	m_imageSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(m_path.c_str());
	m_imageSurface = SDL_ConvertSurface(loadedSurface, m_graphics->GetView()->GetWindowSurface()->format, 0);
	if (m_imageSurface == NULL) fprintf(stderr, "could not optimize image: %s\n", SDL_GetError());
	//m_texture = SDL_CreateTextureFromSurface(m_graphics->GetRenderer(), imageSurface);
	SDL_FreeSurface(loadedSurface);
	
	return true;
}

SDL_Texture* SDLImage::GetTexture()
{
	if (!m_texture && m_imageSurface)
	{
		m_texture = SDL_CreateTextureFromSurface(m_graphics->GetRenderer(), m_imageSurface);
		SDL_FreeSurface(m_imageSurface);
	}
	return m_texture;
}

bool SDLImage::Init()
{
	return true;
}

int SDLImage::getWidth()
{
	return 0;
}

int SDLImage::getHeight()
{
	return 0;
}