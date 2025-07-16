#pragma once
#include "../header/BaseScene.h"
#include "InputManager.h"

class Camera;
/*
* Ishihara
* リザルトシーン
*/
class SceneResult: public BaseScene
{
public:
	SceneResult();
	~SceneResult();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

private:
	/// <summary>
	/// 左クリックの入力処理
	// </summary>
	void OnCursorProc(Vector2 pos);
	void LPushInputProc(Vector2 pos);
	void RPushInputProc(Vector2 pos);
	void LDrackInputProc(Vector2 pos, Vector2 oldPos);
	void RDrackInputProc(Vector2 pos, Vector2 oldPos);
	void LReleaseInputProc(Vector2 pos, Vector2 oldPos);
	void RReleaseInputProc(Vector2 pos, Vector2 oldPos);
	void WheelRotInputProc(Vector2 pos, int rot);
	void EscapeInputProc();

	Camera* _pCamera;

	const float WIN_X = WINDOW_WIDTH;
	const float WIN_Y = WINDOW_HEIGHT;

	const Vector2 TITLE_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (1.0f / 10.0f));
	const Vector2 TITLE_POS =  Vector2(WIN_X / 2.0f, (WIN_Y / 5.0f));
	const int TITLE_FONT_SIZE = 99;
	const Vector2 DAYS_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 DAYS_POS = Vector2(WIN_X / 2.0f, WIN_Y / 2.0f);
	const Vector2 BACK_SIZE = Vector2(WIN_X * (1.0f / 3.0f), WIN_Y * (1.0f / 15.0f));
	const Vector2 BACK_POS =  Vector2(WIN_X / 2.0f, WIN_Y - (WIN_Y / 7.0f));
};
