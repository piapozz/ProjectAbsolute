#pragma once
#include "BasePhase.h"
#include <vector>
class StageManager;
class UIManager;
class Camera;
class OfficerManager;
class OfficerPlayer;
class EventManager;
class UIScreenButton;
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
	void Teardown() override {}

	static std::vector<OfficerPlayer*>& GetSelectOfficerList();

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
	StageManager* _pStageManager;
	UIManager* _pUIManager;
	Camera* _pCamera;
	OfficerManager* _pOfficerManager;
	static std::vector<OfficerPlayer*> _pSelectOfficerList;
	EventManager* _pEventManager;
	UIScreenButton* _pRangeSelect;

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

