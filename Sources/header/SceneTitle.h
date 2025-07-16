#pragma once
#include "BaseScene.h"
#include "InputManager.h"

class Camera;
/*
* Ishihara
* タイトルシーン
*/
class SceneTitle : public BaseScene
{
public:
	SceneTitle();
    ~SceneTitle();

    /// <summary>
    /// 初期化
    /// </summary>
    void Init();
private:
	/// <summary>
	/// 左クリックの入力処理
	/// </summary>
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

	// 座標,サイズ
	const float WIN_X = WINDOW_WIDTH;
	const float WIN_Y = WINDOW_HEIGHT;

	const Vector2 TITLE_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (1.0f / 10.0f));
	const Vector2 TITLE_POS =  Vector2(WIN_X / 4.0f, (WIN_Y / 5.0f));
	const int TITLE_FONT_SIZE = 99;

	// サイズ
	const float BUTTON_SPACING = 100.0f;
	const Vector2 START_POS = Vector2(WIN_X / 4.0f, WIN_Y - (WIN_Y / 3.0f));

	const Vector2 CONTINUE_SIZE = Vector2(WIN_X * (1.0f / 4.0f), WIN_Y * (1.0f / 15.0f));
	const Vector2 NEW_GAME_SIZE = Vector2(WIN_X * (1.0f / 4.0f), WIN_Y * (1.0f / 15.0f));
	const Vector2 EXIT_SIZE = Vector2(WIN_X * (1.0f / 4.0f), WIN_Y * (1.0f / 15.0f));
	const Vector2 CONTINUE_POS = START_POS;
	const Vector2 NEW_GAME_POS = Vector2(START_POS.x, CONTINUE_POS.y + BUTTON_SPACING);
	const Vector2 EXIT_POS = Vector2(START_POS.x, NEW_GAME_POS.y + BUTTON_SPACING);
};

