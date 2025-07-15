#pragma once
#include "BasePhase.h"

class Camera;
/*
 * Sakakura
 * リザルトフェーズ
 */
class PhaseResult : public BasePhase
{
public:
	PhaseResult() {}
	~PhaseResult() {};

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

	// 座標,サイズ
	const float WIN_X = WINDOW_WIDTH;
	const float WIN_Y = WINDOW_HEIGHT;

	const Vector2 TEXT_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 TEXT_POS =  Vector2(WIN_X / 2.0f - 200, (TEXT_SIZE.y / 2.0f));
	const Vector2 MONEY_SIZE = Vector2(WIN_X * (3.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
	const Vector2 MONEY_POS = Vector2(WIN_X / 2.0f - 100, WIN_Y / 2.0f);

	// サイズ
	const Vector2 RESTART_SIZE = Vector2(WIN_X * (1.0f / 5.0f), WIN_Y * (1.0f / 15.0f));
	const Vector2 NEXT_SIZE    = Vector2(WIN_X * (1.0f / 4.0f), WIN_Y * (1.0f / 15.0f));
	const float TOTAL_WIDTH = RESTART_SIZE.x + NEXT_SIZE.x;
	const Vector2 RESTART_POS = Vector2(WIN_X / 2.0f - (TOTAL_WIDTH / 2.0f) + (RESTART_SIZE.x / 2.0f),WIN_Y - (RESTART_SIZE.y / 2.0f));
	const Vector2 NEXT_POS = Vector2(WIN_X / 2.0f + (TOTAL_WIDTH / 2.0f) - (NEXT_SIZE.x / 2.0f),WIN_Y - (NEXT_SIZE.y / 2.0f));


};

