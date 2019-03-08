#include "SDLView.h"
#include "Canvas.h"
#include "Graphics.h"
#include "InputDef.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

SDL_semaphore *gLoadingSemaphore;
int loadingProc(void *data)
{
	Canvas *canvas = (Canvas*)data;

	// create a locked semaphore for synchronizing with loading thread:
	gLoadingSemaphore = SDL_CreateSemaphore(0);

	// load the game:
	canvas->LoadContent();

	//canvas->LoadComplete();
	// unlock the loading semaphore:
	SDL_SemPost(gLoadingSemaphore);

	return 0;
}

MouseButton GetMouseButton(SDL_Event evt)
{
	switch (evt.button.button)
	{
	case SDL_BUTTON_LEFT:
		return MouseButton::MOUSE_LEFT;
		break;
	case SDL_BUTTON_RIGHT:
		return MouseButton::MOUSE_RIGHT;
		break;
	case SDL_BUTTON_MIDDLE:
		return MouseButton::MOUSE_MIDDLE;
		break;
	default:

		break;
	}

}

SDLView::SDLView()
{
	m_mainCanavas = nullptr;
}

bool SDLView::Init(int width, int height, const char* title)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	TTF_Init();
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);

	//Initialize SDL_mixer 
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	m_window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_SHOWN
	);

	m_screenSurface = SDL_GetWindowSurface(m_window);

	m_mainCanavas->preInitLoad();

	m_mainCanavas->preInitDraw(m_graphics);

	m_mainCanavas->Initialize();

	return true;
}


void* SDLView::GetWindow()
{
	return m_window;
}

bool SDLView::Run()
{
	bool isRunning = true;
	while (isRunning)
	{
		CheckLoadingComplete();
		// Get the next event
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
					m_mainCanavas->WindowResized(event.window.data1, event.window.data2);
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					m_mainCanavas->WindowFocus(true);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					m_mainCanavas->WindowFocus(false);
					break;
				case SDL_WINDOWEVENT_MOVED:
					m_mainCanavas->WindowMoved(event.window.data1, event.window.data2);
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					m_mainCanavas->WindowVisibilityChanged(false);
				case SDL_WINDOWEVENT_SHOWN:
					m_mainCanavas->WindowVisibilityChanged(true);
					break;
				case SDL_WINDOWEVENT_CLOSE:
					m_mainCanavas->WindowClosed();
					isRunning = false;
					break;
				default:
					break;
				}
			}
			break;
			case SDL_KEYDOWN:
			{
				int index = event.key.keysym.scancode;
				const Uint8 *state = SDL_GetKeyboardState(NULL);
				bool isPressed = state[event.key.keysym.scancode];
				m_mainCanavas->OnKeyboardEvent((KeyboardKey)index, InputEventType::INPUT_DOWN, (InputEventState)isPressed);
			}
				break;
			case SDL_KEYUP:
			{
				int index = event.key.keysym.scancode;
				const Uint8 *state = SDL_GetKeyboardState(NULL);
				bool isPressed = state[event.key.keysym.scancode];
				m_mainCanavas->OnKeyboardEvent((KeyboardKey)index, InputEventType::INPUT_UP, (InputEventState)isPressed);
			}
				break;
			case SDL_MOUSEBUTTONDOWN:
			{
				int x, y; SDL_GetMouseState(&x, &y);
				m_mainCanavas->OnMouseMotion(x, y);

				MouseButton button = GetMouseButton(event);
				bool isPressed = SDL_BUTTON(event.button.button);
				m_mainCanavas->OnMouseEvent(button, InputEventType::INPUT_DOWN, (InputEventState)isPressed);
			}
			break;
			case SDL_MOUSEBUTTONUP:
			{
				int x, y; SDL_GetMouseState(&x, &y);
				m_mainCanavas->OnMouseMotion(x, y);

				MouseButton button = GetMouseButton(event);
				bool isPressed = SDL_BUTTON(event.button.button);
				m_mainCanavas->OnMouseEvent(button, InputEventType::INPUT_UP, (InputEventState)isPressed);
			}
			break;
			case SDL_MOUSEMOTION:
				int x, y; SDL_GetMouseState(&x, &y);
				m_mainCanavas->OnMouseMotion(x, y);
				break;
			case SDL_QUIT:
				m_mainCanavas->WindowClosed();
				isRunning = false;
				break;
			default:
				break;
			}
		}
		m_mainCanavas->Draw(m_graphics);
		m_graphics->Flush();
	}

	m_mainCanavas->Clear();
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	return 1;
}

void SDLView::Destroy()
{
	//m_mainCanavas->Clear();
	//SDL_DestroyWindow(m_window);
	//SDL_Quit();
}

void SDLView::EventUpdate()
{
	// Get the next event
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
		{
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				m_mainCanavas->WindowResized(event.window.data1, event.window.data2);
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				m_mainCanavas->WindowFocus(true);
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				m_mainCanavas->WindowFocus(false);
				break;
			case SDL_WINDOWEVENT_MOVED:
				m_mainCanavas->WindowMoved(event.window.data1, event.window.data2);
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				m_mainCanavas->WindowVisibilityChanged(false);
			case SDL_WINDOWEVENT_SHOWN:
				m_mainCanavas->WindowVisibilityChanged(true);
				break;
			case SDL_WINDOWEVENT_CLOSE:
				m_mainCanavas->WindowClosed();
				Destroy();
				break;
			default:
				break;
			}
		}
		break;
		case SDL_QUIT:
			m_mainCanavas->WindowClosed();
			Destroy();
			break;
		default:
			break;
		}
	}
}
void SDLView::CheckLoadingComplete()
{
	if (gLoadingSemaphore != NULL && SDL_SemTryWait(gLoadingSemaphore) == 0)
	{
		// get rid of the semaphore:
		SDL_DestroySemaphore(gLoadingSemaphore);
		gLoadingSemaphore = NULL;

		m_mainCanavas->LoadComplete();
	}
}

SDL_Surface* SDLView::GetWindowSurface()
{
	return m_screenSurface;
}

void SDLView::StartLoading()
{
	//loadingProc(m_mainCanavas);
	gLoadingSemaphore = nullptr;

	SDL_CreateThread(loadingProc, "loadingProc", m_mainCanavas);
}

void SDLView::SetWindowFullScreen(bool value)
{
	if(value)
		SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(m_window, 0);
}

