#pragma once
#include "BasePhase.h"
class StageManager;
class CameraController;
class OfficerManager;
/*
 * Sakakura
 * メインフェーズ
 */
class PhaseMain : public BasePhase
{
public:
	PhaseMain() { Init(); }
	~PhaseMain() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:
	StageManager* _stageManager;
	CameraController* _cameraController;
	OfficerManager* _pOfficerManager;
};

