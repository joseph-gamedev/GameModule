#include "SDLGraphics.h"
#include "SDLView.h"
#include "SDLImage.h"
#include "Vector2.h"
#include "Rectangle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

SDLGraphics::SDLGraphics(SDLView* view)
	: m_view(view)
{

}

SDLGraphics::~SDLGraphics()
{

}

void SDLGraphics::DrawImage(Image* img, const Rectanglef* source, const Rectanglef* target)
{
	SDLImage* sdlImage = static_cast<SDLImage*> (img);
	SDL_Rect* src = NULL;
	SDL_Rect* dest = NULL;

	if (source)
	{
		SDL_Rect  srcRect = { source->x,source->y,source->width,source->height };
		src = &srcRect;
	}
	
	if (target)
	{
		SDL_Rect  destRect = { target->x,target->y,target->width,target->height };
		dest = &destRect;
	}
	
	if (sdlImage->GetTexture())
	{
		SDL_RenderCopy(m_renderer, sdlImage->GetTexture(), src, dest);
	}
}

void SDLGraphics::DrawImage(Image* img, const float x, const float y, const float width, const float height)
{
	SDL_Rect rect = { x,y,width,height };
	SDLImage* sdlImage = static_cast<SDLImage*> (img);
	if (sdlImage->GetTexture())
	{
		SDL_RenderCopy(m_renderer, sdlImage->GetTexture(), NULL, &rect);
	}
}

void SDLGraphics::DrawLine(const float x1, const float y1, const float x2, const float y2)
{
	SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
}

void SDLGraphics::DrawLines(Vector2f* points, int count)
{
	for (Vector2f* point = points; point < &points[count-1]; point++)
	{
		Vector2f p1 = *point;
		Vector2f p2 = *(point+1);
		DrawLine(p1.X,p1.Y,p2.X,p2.Y);
	}
}

void SDLGraphics::DrawPoint(const float x, const float y)
{
	SDL_RenderDrawPoint(m_renderer, x,y);
}

void SDLGraphics::DrawPoints(Vector2f* points, int count)
{
	for (Vector2f* point = points; point < &points[count - 1]; point++)
	{
		Vector2f p1 = *point;
		DrawPoint(p1.X, p1.Y);
	}
}

void SDLGraphics::DrawRectangle(const float x, const float y, const float width, const float height)
{
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderDrawRect(m_renderer, &rect);
}

void SDLGraphics::DrawRectangles(Rectanglef* rectangle, int count)
{

}

void SDLGraphics::FillRectangle(const float x, const float y, const float width, const float height)
{
}

void SDLGraphics::Move(const float x, const float y)
{

}

void SDLGraphics::SetColor(const int red, const int green, const int blue, const int alpha)
{
	m_color = { red, green, blue, alpha };
	SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
}

bool SDLGraphics::Init()
{
	IMG_Init(IMG_INIT_JPG);
	

	SDL_Window* window = static_cast<SDL_Window*>(m_view->GetWindow());

	m_renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if (!m_renderer)
	{
		SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void SDLGraphics::Destroy()
{
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(m_renderer);
}

void SDLGraphics::ClearColor(const int red, const int green, const int blue, const int alpha)
{
	SDL_SetRenderDrawColor(m_renderer, red, green, blue, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_renderer);
}

void SDLGraphics::Flush()
{
	SDL_RenderPresent(m_renderer);
}

SDL_Renderer* SDLGraphics::GetRenderer()
{
	return m_renderer;
}

SDLView* SDLGraphics::GetView()
{
	return m_view;
}

Vector2f SDLGraphics::GetWindowSize()
{
	int width, height;
	SDL_Window* window = static_cast<SDL_Window*>(m_view->GetWindow());
	SDL_GetWindowSize(window, &width, &height);
	return Vector2f(width, height);
}

void SDLGraphics::DrawText(const char* text, const float x, const float y, const float width, const float height)
{
	SDL_Color color = { m_color.r, m_color.g, m_color.b, m_color.a };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(m_font, text, color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderCopy(m_renderer, tex, NULL, &rect);
}

void* SDLGraphics::CreateFont(const char* font, int size)
{
	TTF_Font* ft = TTF_OpenFont("E:\\GameFramework\\res\\Roboto-Black.ttf", size);
	return ft;
}

void SDLGraphics::SetFont(void* font)
{
	m_font = static_cast<TTF_Font*>(font);
}

void* const SDLGraphics::GetFont() const
{
	return m_font;
}