#pragma once

template<typename T>
class Vector2
{
public:
	T X;
	T Y;
	
	static const Vector2 Zero;
	static const Vector2 One;
	
	Vector2(T X, T Y);
	
};

template<typename T>
Vector2<T>::Vector2(T x, T y)
	: X(x)
	, Y(y)
{

}

typedef Vector2<float> Vector2f;