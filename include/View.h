#pragma once 

class Canvas;
class Graphics;

class View
{
public:
	virtual ~View() {}

	virtual bool Init(int width, int height, const char* title) = 0;

	virtual void StartLoading() {}

	virtual bool Run() = 0;

	virtual void* GetWindow() = 0;

	virtual void Destroy() = 0;

	virtual void SetWindowFullScreen(bool value) = 0;

	void SetGraphics(Graphics* g) { m_graphics = g; }

	void SetMainCanvas(Canvas* canvas) { m_mainCanavas = canvas; }

protected:
	Canvas   *m_mainCanavas;
	Graphics *m_graphics;
};