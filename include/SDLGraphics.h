#pragma once 


#include "Graphics.h"
//#include <SDL_ttf.h>

class SDLView;
struct SDL_Renderer;

class SDLGraphics : public Graphics
{
public:
	SDLGraphics(SDLView* view);
	virtual ~SDLGraphics();

	virtual void DrawImage(Image* img, const Rectanglef* source, const Rectanglef* target) override;

	virtual void DrawImage(Image* img, const float x, const float y, const float width, const float height) override;

	virtual void DrawLine(const float x1, const float y1, const float x2, const float y2) override;

	virtual void DrawLines(Vector2f* points, int count) override;

	virtual void DrawPoint(const float x, const float y) override;

	virtual void DrawPoints(Vector2f* points, int count) override;

	virtual void DrawRectangle(const float x, const float y, const float width, const float height) override;

	virtual void DrawRectangles(Rectanglef* rectangle, int count) override;

	virtual void FillRectangle(const float x, const float y, const float width, const float height) override;

	virtual void Move(const float x, const float y) override;

	virtual void SetColor(const int red, const int green, const int blue, const int alpha) override;

	virtual void ClearColor(const int red, const int green, const int blue, const int alpha) override;

	virtual void Flush() override;

	virtual bool Init() override;

	virtual void Destroy() override;

	virtual Vector2f GetWindowSize() override;

	virtual void DrawText(const char* text, const float x, const float y, const float width, const float height) override;

	virtual void* CreateFont(const char* font, int size) override;

	virtual void SetFont(void* font) override;

	virtual void* const GetFont() const override;


	SDL_Renderer* GetRenderer();

	SDLView* GetView();

private:
	SDL_Renderer *  m_renderer;
	SDLView *		m_view;
	struct _TTF_Font*		m_font;
	Color           m_color;
};