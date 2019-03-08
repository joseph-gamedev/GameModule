#include "Application.h"
#include "Defines.h"
#include "SDLGraphics.h"
#include "SDLView.h"
#include <iostream>

Application::Application(GraphicsType type)
	: m_graphicsType(type)
	, m_graphics(nullptr)
	, m_view(nullptr)
{

}

Application::~Application()
{
	Destroy();
}

bool Application::Init(Canvas* canvas, int width, int height, const char* title)
{
	switch (m_graphicsType)
	{
	case GraphicsType::SDL_GRAPHICS:
		m_view = new SDLView();
		m_graphics = new SDLGraphics(dynamic_cast<SDLView*>(m_view));
		m_view->SetGraphics(m_graphics);
		m_view->SetMainCanvas(canvas);
		m_view->Init(width,height,title);
		m_graphics->Init();
		m_view->StartLoading();
		break;
	case GraphicsType::OPENGL_GRAPHICS:
		break;
	default:
		break;
	}
	
	return true;
}


void Application::Destroy()
{
	SAFEDESTROY(m_graphics);
	SAFEDESTROY(m_view);
}

int Application::Run()
{
	return m_view->Run();
}