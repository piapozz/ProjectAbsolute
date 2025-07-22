#pragma once
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>
class BaseObject;

// 二次元ベクトル
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

	void operator+=(const float& num)
	{
		x += num;
		y += num;
	}

	void operator-=(const float& num)
	{
		x -= num;
		y -= num;
	}

	void operator*=(const float& num)
	{
		x *= num;
		y *= num;
	}

	void operator/=(const float& num)
	{
		x /= num;
		y /= num;
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

	Vector2(const Vector2& vec)
	{
		x = vec.x;
		y = vec.y;
	}

	inline static Vector2 zero()
	{
		Vector2 temp;
		temp.x = 0;
		temp.y = 0;
		return temp;
	}

	inline static Vector2 one()
	{
		Vector2 temp;
		temp.x = 1;
		temp.y = 1;
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

/// <summary>
/// スクリーン座標からステージ座標に変換する
/// </summary>
/// <param name="screenPos"></param>
/// <param name="cameraHeight"></param>
/// <param name="cameraPos"></param>
/// <returns></returns>
Vector2 GetScreen2StagePos(Vector2 screenPos, float cameraHeight, Vector2 cameraPos);

// オブジェクトの基本情報
struct Transform
{
public:
	Vector2 position;
	Vector2 scale;
	BaseObject* parent;

	Transform()
	{
		position = Vector2(0, 0);
		scale = Vector2(0, 0);
		parent = nullptr;
	}

	Transform(Vector2 setPosition, Vector2 setScale, BaseObject* setParent = nullptr)
		: position(setPosition), scale(setScale), parent(setParent){}
	Transform GetWorldTransform();
	inline bool IsChild() { return parent != nullptr; }
};

/// <summary>
/// 浮動点小数の精度を設定する
/// </summary>
/// <returns></returns>
inline std::string SetPrecision(float value, int precision = 1)
{
	std::ostringstream oss;
	float precisionFactor = powf(10.0f, -precision);
	if (std::abs(value - static_cast<int>(value)) < precisionFactor)
		oss << static_cast<int>(value);
	else
		oss << std::fixed << std::setprecision(precision) << value;

	return oss.str();
}

enum class AttachDirection {
	Top,
	Bottom,
	Left,
	Right
};

enum class Align {
	Start,
	Center
};

void Attach2DArray(std::vector<std::vector<int>>& base,
				   const std::vector<std::vector<int>>& patch,
				   AttachDirection direction,
				   Align align = Align::Start);