#pragma once
#include "BasePhase.h"
#include <vector>
class StageManager;
class Camera;
class OfficerManager;
class OfficerPlayer;
class EventManager;
class UIScreenButton;
class SelectOperationUI;
class UIEntity;
class UIOfficer;
class ContinueResultUI;
class GameOverUI;

/*
 * Sakakura
 * メインフェーズ
 */
class PhaseMain : public BasePhase
{
public:
	PhaseMain(){ };
	~PhaseMain() {};

	void Init() override;
	void Teardown() override {}

	void ChangeResultPhase(int value);
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
	Camera* _pCamera;
	OfficerManager* _pOfficerManager;
	static std::vector<OfficerPlayer*> _pSelectOfficerList;
	UIScreenButton* _pRangeSelect;
	SelectOperationUI* _pSelectOperationUI;
	UIEntity* _pEntityUI;
	UIOfficer* _pOfficerUI;
	ContinueResultUI* _pResultUI;
	GameOverUI* _pGameOverUI;
};

