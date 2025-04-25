#pragma once
#include "DxLib.h"
#include "../header/CommonModule.h"

/*
 * Sakakura
 * ÉJÉÅÉâÇÃëÄçÏÉNÉâÉX
 */
class CameraController
{
public:
	static Vector2 stagePosition;
	static float heightSize;
	static Vector2 GetScreen2StagePos(Vector2 screenPos);

	CameraController();
	virtual ~CameraController(){}

	void RPushEvent(Vector2 screenPos);
	void RDrackEvent(Vector2 screenPos);
	void WheelEvent(int up);
	void UpdateCamera();

private:
	const int _MIN_HEIGHT_SIZE = 100;
	const int _MAX_HEIGHT_SIZE = 1000;
	const float _Z_POS_OFFSET = -100.0f;
	const float _Z_TARGET_FAR = 1000.0f;
	const float _DEFAULT_POS_X = 500.0f;
	const float _DEFAULT_POS_Y = 500.0f;

	Vector2 _prevCursorPos;
	Vector2 _pushPos;

	void SetCameraOrtho(int wheel);
};
