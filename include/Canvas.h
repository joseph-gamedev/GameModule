#pragma once 

#include "InputDef.h"

class Application;
class View;
class Graphics;

class Canvas
{
public:
	Canvas(Application* app) 
	: m_application(app)
	{}
	virtual ~Canvas() {}

	virtual void preInitLoad() {}
	virtual void preInitDraw(Graphics *g) {}
	virtual void Initialize() = 0;
	virtual void LoadContent() = 0;
	virtual void LoadComplete() {}
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(Graphics* g) = 0;
	virtual void Clear() = 0;

	virtual void OnKeyboardEvent(KeyboardKey key, InputEventType type, InputEventState state) {}
	virtual void OnMouseEvent(MouseButton button, InputEventType type, InputEventState state) {}
	virtual void OnMouseMotion(int x, int y) {};

	virtual void WindowResized(int newWidth, int newHeight) {}
	virtual void WindowFocus(bool isFocused) {}
	virtual void WindowFullScreenToggle(bool isFullscreen) {}
	virtual void WindowMoved(int x, int y) {}
	virtual void WindowClosed() {}
	virtual void WindowVisibilityChanged(bool isShown) {}
protected:
	Application* m_application;
};