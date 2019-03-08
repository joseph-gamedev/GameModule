#pragma once 

template<typename T>
class Rectangle
{
public:
	Rectangle();
	Rectangle(T x, T y, T width, T height);
	Rectangle (const Vector2<T>& min, const Vector2<T>& max);
 	Rectangle (const Rectangle<T> &other);
	Rectangle (const Rectangle<T> &&other);
	Rectangle& operator= (const Rectangle &other);
	Rectangle& operator+ (const Vector2<T> &point) const;
	Rectangle& operator- (const Vector2<T> &point) const;
	Rectangle& operator+= (const Vector2<T> &point);
	Rectangle& operator-= (const Vector2<T> &point);
	bool operator< (const Rectangle<T> &other) const; 
	bool operator== (const Rectangle<T> &other) const;
	bool operator!= (const Rectangle<T> &other) const;	
	bool Equals(const Rectangle<T> &other) const;
	bool Contains(const Vector2<T>& point) const;
	bool Contains(const Rectangle<T>& other) const;
	bool Contains(T x, T y) const;
	void Grow(T by);
	void Grow(T xBy, T yBy);
	void GetCenterAndExtents(const Vector2<T>& center, const Vector2<T>&extent);
	void Move(T x, T y);
	bool Overlaps(const Rectangle<T>& other) const;
	Vector2<T> GetCenter() const;
	Vector2<T> GetExtents() const;
	Vector2<T> GetMax() const ;
	Vector2<T> GetMin() const;
	Vector2<T> GetSize() const;
	T GetX() const;
	T GetY() const;
	T GetWidth() const;
	T GetHeight() const;
	void SetX(T x);
	void SetY(T y);
	void SetWidth(T width);
	void SetHeight(T height);
	const char* ToString();
	static const Rectangle<T> ZeroRectangle;
	static const Rectangle<T> UnitRectangle;

public:
	T x;
	T y;
	T width;
	T height;
};

template<typename T>
Rectangle<T>::Rectangle(T _x, T _y, T _width, T _height)
	: x(_x)
	, y(_y)
	, width(_width)
	, height(_height)
{

}

typedef Rectangle<float> Rectanglef;