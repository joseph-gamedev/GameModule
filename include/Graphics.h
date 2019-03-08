#pragma once 

#include "Vector2.h"
#include "Rectangle.h"

class Image;

struct Color
{
	int r;
	int g;
	int b;
	int a;
};

enum class BlendMode
{
	BLENDMODE_NONE,
	BLENDMODE_BLEND,
	BLENDMODE_ADD,
	BLENDMODE_MOD
};

class Font;

class Graphics 
{
public:
	virtual ~Graphics() {}
	
	virtual void DrawImage(Image* img, const Rectanglef* source, const Rectanglef* target) = 0;

	virtual void DrawImage(Image* img, const float x, const float y, const float width, const float height) = 0;
	
	virtual void DrawLine(const float x1, const float y1, const float x2, const float y2) = 0;
	
	virtual void DrawLines(Vector2f* points, int count) {}
	
	virtual void DrawPoint(const float x, const float y) {}
	
	virtual void DrawPoints(Vector2f* points, int count) {}
	
	virtual void DrawRectangle(const float x, const float y, const float width, const float height) = 0;
	
	virtual void DrawRectangles(Rectanglef* rectangle, int count) = 0;
	
	virtual void FillRectangle(const float x, const float y, const float width, const float height) = 0;
	
	virtual void Move(const float x, const float y) {}
	
	virtual void SetColor(const int red, const int green, const int blue, const int alpha) = 0;
	
	virtual void ClearColor(const int red, const int green, const int blue, const int alpha) = 0;

	virtual void Flush() = 0;

	void SetBlendMode(BlendMode mode);

	virtual bool Init() = 0;

	virtual void Destroy() = 0;
	
	virtual Vector2f GetWindowSize() = 0;

	virtual void DrawText(const char* text, const float x, const float y, const float width, const float height) = 0;

	virtual void* CreateFont(const char* font, int size) = 0;

	virtual void SetFont(void* font) = 0;

	virtual void* const GetFont() const = 0;
};