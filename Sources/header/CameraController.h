#pragma once
#include "DxLib.h"
#include "../header/CommonModule.h"

class CameraController
{
public:
	CameraController();
	void Update();
	inline float GetHeightSize(){ return heightSize; }
	inline Vector2 GetCameraPos(){ return Vector2(position.x, position.y); };

private:
	VECTOR position;
	float pitch; // è„â∫
	float yaw;   // ç∂âE
	float moveSpeed;
	float rotateSpeed;
	float heightSize;

	int prevMouseX, prevMouseY;
	bool isRightButtonPressed;

	void HandleMouse();
	void HandleKeyboard();
	void UpdateCamera();
	void SetCameraOrtho(int wheel);
};
