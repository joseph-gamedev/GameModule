#pragma once

#include "Canvas.h"

class TestCanvas : public Canvas
{
public:
	TestCanvas(Application* app):
	Canvas(app)
	{}
	virtual ~TestCanvas() {}
	virtual void preInitLoad() {}
	virtual void preInitDraw(Graphics *g) {}
	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void LoadComplete() override;
	virtual void Update(float deltaTime) override;
	virtual void Draw(Graphics* g) override;
	virtual void Clear() override;

	virtual void OnKeyboardEvent(KeyboardKey key, InputEventType type, InputEventState state) override;
	virtual void OnMouseEvent(MouseButton button, InputEventType type, InputEventState state) override;
	virtual void OnMouseMotion(int x, int y) override;

private:
	class SDLImage* m_img;
	class SDLAudioMusic* m_music;
	int count = 0;
};