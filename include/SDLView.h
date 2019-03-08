#pragma once 

#include "View.h"

class SDL_Surface;

class SDLView : public View
{
public:
	SDLView();
	virtual ~SDLView() {}

	virtual bool Init(int width, int height, const char* title) override;

	virtual bool Run() override;

	virtual void* GetWindow() override;

	virtual void Destroy() override;

	virtual void StartLoading() override;

	SDL_Surface* GetWindowSurface();

	virtual void SetWindowFullScreen(bool value) override;

private:
	void EventUpdate();
	void CheckLoadingComplete();

private:
	class SDL_Window  *m_window;
	class SDL_Surface *m_screenSurface;
};