#pragma once
#include "DxLib.h"
#include "../header/CommonModule.h"

class CameraController
{
public:
	CameraController();
	virtual ~CameraController(){}

	inline float GetHeightSize(){ return _heightSize; }
	inline Vector2 GetCameraPos(){ return Vector2(_position.x, _position.y); };
	void RPushEvent(Vector2 screenPos);
	void RDrackEvent(Vector2 screenPos);
	void WheelEvent(int up);

private:
	const int MIN_HEIGHT_SIZE = 100;
	const int MAX_HEIGHT_SIZE = 1000;

	VECTOR _position;
	float _heightSize;
	Vector2 _prevCursorPos;
	Vector2 _pushPos;

	void UpdateCamera();
	void SetCameraOrtho(int wheel);
};
