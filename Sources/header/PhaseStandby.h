#pragma once
#include "BasePhase.h"

class Camera;
/*
 * Sakakura
 * スタンバイフェーズ
 */
class PhaseStandby : public BasePhase
{
public:
	PhaseStandby() {}
	~PhaseStandby() {};

	void Init() override;
	void Teardown() override {};

protected:
	void OnCursorProc(Vector2 pos) override;
	void LPushInputProc(Vector2 pos) override;
	void RPushInputProc(Vector2 pos) override;
	void LDrackInputProc(Vector2 pos, Vector2 oldPos) override;
	void RDrackInputProc(Vector2 pos, Vector2 oldPos) override;
	void LReleaseInputProc(Vector2 pos, Vector2 oldPos) override;
	void RReleaseInputProc(Vector2 pos, Vector2 oldPos) override;
	void WheelRotInputProc(Vector2 pos, int rot) override;
	void EscapeInputProc() override;

private:

	Camera* _pCamera;

	// 座標,サイズ(相対割合)

	const float WIN_X = WINDOW_WIDTH;
	const float WIN_Y = WINDOW_HEIGHT;

	// 開始ボタン
	const Vector2 START_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 START_POS =  Vector2(WIN_X - (START_SIZE.x / 2.0f), (START_SIZE.y / 2.0f));
	// 控え職員
	const Vector2 OFFICERLIST_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (12.0f / 20.0f));
	const Vector2 OFFICERLIST_POS =  Vector2(WIN_X - (OFFICERLIST_SIZE.x / 2.0f), WIN_Y - (OFFICERLIST_SIZE.y / 2.0f));
	// 職員詳細
	const Vector2 OFFICCER_UI_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (8.0f / 20.0f));
	const Vector2 OFFICCER_UI_POS =  Vector2(WIN_X - (OFFICCER_UI_SIZE.x / 2.0f), (OFFICCER_UI_SIZE.y / 2.0f));
	// 部門
	const Vector2 DIVISION_SIZE = Vector2(WIN_X * (12.0f / 20.0f), WIN_Y * (18.0f / 20.0f));
	const Vector2 DIVISION_POS =  Vector2((DIVISION_SIZE.x / 2.0f), (DIVISION_SIZE.y / 2.0f));
	// 所持金
	const Vector2 MONEY_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 MONEY_POS =  Vector2((MONEY_SIZE.x / 2.0f), WIN_Y - (MONEY_SIZE.y / 2.0f));
	// 雇用ボタン
	const Vector2 HIRE_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 HIRE_POS =  Vector2(WIN_X - (HIRE_SIZE.x / 2.0f), (HIRE_SIZE.y / 2.0f) + START_SIZE.y);
};

