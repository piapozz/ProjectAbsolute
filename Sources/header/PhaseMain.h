#pragma once
#include "BasePhase.h"
class StageManager;
class CameraController;
class OfficerManager;
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
	void LClickInputProc(Vector2 pos, Vector2 oldPos) override;
	void RClickInputProc(Vector2 pos, Vector2 oldPos) override;
	void EscapeInputProc() override;

private:
	StageManager* _pStageManager;
	CameraController* _pCameraController;
	OfficerManager* _pOfficerManager;

	/// <summary>
	/// �X�N���[�����W����X�e�[�W���W�̎擾
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

