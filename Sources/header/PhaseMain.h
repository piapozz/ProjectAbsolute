#pragma once
#include "BasePhase.h"
#include <vector>
class StageManager;
class CameraController;
class OfficerManager;
class OfficerPlayer;
class EventManager;
/*
 * Sakakura
 * メインフェーズ
 */
class PhaseMain : public BasePhase
{
public:
	PhaseMain() {}
	~PhaseMain() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void LPushInputProc(Vector2 pos) override;
	void RPushInputProc(Vector2 pos) override;
	void LDrackInputProc(Vector2 pos) override;
	void RDrackInputProc(Vector2 pos) override;
	void LReleaseInputProc(Vector2 pos, Vector2 oldPos) override;
	void RReleaseInputProc(Vector2 pos, Vector2 oldPos) override;
	void WheelRotInputProc(Vector2 pos, int rot) override;
	void EscapeInputProc() override;

private:
	StageManager* _pStageManager;
	CameraController* _pCameraController;
	OfficerManager* _pOfficerManager;
	std::vector<OfficerPlayer*> _pPlayerOfficerList;
	EventManager* _pEventManager;

	/// <summary>
	/// スクリーン座標からステージ座標の取得
	/// </summary>
	/// <returns></returns>
	Vector2 GetScreen2StagePos(Vector2 screenPos);

	std::vector<std::vector<int>> _stageData ={
		{1, 2, 2, 2, 2, 2, 1}, 
		{3, 4, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 1, 2, 2, 1},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 2, 2, 2, 1},
	};
};

