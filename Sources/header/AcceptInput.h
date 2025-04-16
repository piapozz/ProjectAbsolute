#pragma once
#include "../header/CommonModule.h"
#include "DxLib.h"

/*
* Sakakura
* ���͎�t
*/
class AcceptInput
{
public:
	// ���͂̎��
	enum class InputType
	{
		LeftClick = 0,
		RightClick,
	};

	AcceptInput(){}
	virtual ~AcceptInput(){}

	Vector2 GetLClickWorldPos();
	Vector2 GetRClickWorldPos();
	Vector2 GetLClickScreenPos(){};
	Vector2 GetRClickScreenPos(){};
};

