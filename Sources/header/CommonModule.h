#pragma once
#include <math.h>

// “ñŽŸŒ³ƒxƒNƒgƒ‹
struct Vector2
{
public:
	float x;
	float y;

	Vector2 operator+(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x + vec.x;
		temp.y = y + vec.y;

		return temp;
	}

	Vector2 operator-(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x - vec.x;
		temp.y = y - vec.y;

		return temp;
	}

	Vector2 operator*(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x * vec.x;
		temp.y = y * vec.y;

		return temp;
	}

	Vector2 operator+(const float& num) const
	{
		Vector2 temp;

		temp.x = x + num;
		temp.y = y + num;

		return temp;
	}

	Vector2 operator-(const float& num) const
	{
		Vector2 temp;

		temp.x = x - num;
		temp.y = y - num;

		return temp;
	}

	Vector2 operator*(const float& num) const
	{
		Vector2 temp;

		temp.x = x * num;
		temp.y = y * num;

		return temp;
	}

	Vector2 operator/(const float& num) const
	{
		Vector2 temp;

		temp.x = x / num;
		temp.y = y / num;

		return temp;
	}

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(const float& X,const float& Y)
	{
		x = X;
		y = Y;
	}

	inline static Vector2 zero()
	{
		Vector2 temp;
		temp.x = 0;
		temp.y = 0;
		return temp;
	}

	static float Distance(const Vector2& vec1,const Vector2& vec2)
	{
		return Size(vec1 - vec2);
	}

	inline float size() const
	{
		return sqrtf(powf(x,2) + powf(y,2));
	}

	inline static float Size(const Vector2& vec)
	{
		return sqrtf(powf(vec.x,2) + powf(vec.y,2));
	}

	void normalize()
	{
		float distance = size();

		if(distance == 0) return;

		x /= distance;
		y /= distance;
	}

	inline static Vector2 Normalize(const Vector2& vec)
	{
		Vector2 temp;
		float distance = vec.size();

		temp.x = vec.x / distance;
		temp.y = vec.y / distance;

		return temp;
	}

	inline static float Dot(const Vector2& vec1,const Vector2& vec2)
	{
		return vec1.x * vec2.x + vec2.y * vec1.y;
	}

	inline static float Cross(const Vector2& vec1,const Vector2& vec2)
	{
		return vec1.x * vec2.y - vec2.x * vec1.y;
	}
};