#pragma once
#include "BasePhase.h"
class StageCreator;
class CameraController;
/*
 * Sakakura
 * ���C���t�F�[�Y
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
	StageCreator* _stageCreator;
	CameraController* _cameraController;
};

