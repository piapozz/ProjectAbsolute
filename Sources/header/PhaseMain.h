#pragma once
#include "BasePhase.h"
#include <vector>
class StageManager;
class UIManager;
class CameraController;
class OfficerManager;
class OfficerPlayer;
class EventManager;
class UIScreenButton;
/*
 * Sakakura
 * ���C���t�F�[�Y
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
	CameraController* _pCameraController;
	OfficerManager* _pOfficerManager;
	std::vector<OfficerPlayer*> _pSelectOfficerList;
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

