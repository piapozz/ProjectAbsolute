#pragma once
#include "DxLib.h"

class CameraController
{
public:
	CameraController();
	void Update();

private:
	VECTOR position;
	float pitch; // è„â∫
	float yaw;   // ç∂âE
	float moveSpeed;
	float rotateSpeed;

	int prevMouseX, prevMouseY;
	bool isRightButtonPressed;

	void HandleMouse();
	void HandleKeyboard();
	void UpdateCamera();
};
