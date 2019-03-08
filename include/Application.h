#pragma once 

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class Canvas;
class Graphics;
class View;

enum class GraphicsType
{
	SDL_GRAPHICS, 
	OPENGL_GRAPHICS
};

class Application
{
public:
	Application(GraphicsType type = GraphicsType::SDL_GRAPHICS);
	~Application();
	
	bool Init(Canvas* canvas, int width , int height, const char* title);

	int Run();

	void Destroy();

	View* GetView() { return m_view; }

	Graphics* GetGraphics() { return m_graphics;  }

	void AddCanvas();

	void RemoveCanvas();

	void ShowCanvas();
	
private:
	Graphics*	 m_graphics;
	GraphicsType m_graphicsType;
	View*		 m_view;
};