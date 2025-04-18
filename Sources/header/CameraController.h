#pragma once
#include "DxLib.h"
#include "../header/CommonModule.h"

class CameraController
{
public:
	CameraController();
	virtual ~CameraController(){}

	void Update();
	inline float GetHeightSize(){ return heightSize; }
	inline Vector2 GetCameraPos(){ return Vector2(position.x, position.y); };
	void RPushEvent(Vector2 screenPos);
	void RReleaseEvent();
	void WheelEvent(int up);

private:
	const int MIN_HEIGHT_SIZE = 100;
	const int MAX_HEIGHT_SIZE = 1000;

	VECTOR position;
	float heightSize;
	int prevMouseX, prevMouseY;
	bool isRightButtonPressed;
	Vector2 _clickPos;

	void HandleMouse();
	void UpdateCamera();
	void SetCameraOrtho(int wheel);
};
