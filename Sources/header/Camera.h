#pragma once
#include "../header/CommonModule.h"
#include "../header/BaseObject.h"


/*
 * Sakakura
 * ÉJÉÅÉâÇÃëÄçÏÉNÉâÉX
 */
class Camera : public BaseObject
{
public:
	Camera();
	virtual ~Camera(){}
	static Camera* instance;

	void RPushEvent(Vector2 screenPos);
	void RDrackEvent(Vector2 screenPos);
	void WheelEvent(int up);
	void UpdateCamera();
	inline float GetHeight(){ return _heightSize; }

private:
	const int _MIN_HEIGHT_SIZE = 100;
	const int _MAX_HEIGHT_SIZE = 1000;
	const float _Z_POS_OFFSET = -100.0f;
	const float _Z_TARGET_FAR = 1000.0f;
	const float _DEFAULT_POS_X = 500.0f;
	const float _DEFAULT_POS_Y = 500.0f;

	Vector2 _prevCursorPos;
	Vector2 _pushPos;
	float _heightSize;

	void SetCameraOrtho(int wheel);
};
