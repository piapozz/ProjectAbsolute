#pragma once
#include <vector>
#include "PhaseSelect.h"
#include "PhaseStandby.h"
#include "PhaseMain.h"
#include "PhaseResult.h"
class ObjectManager;
/*
 * Sakakura
 * �t�F�[�Y�Ǘ��N���X
 */
class PhaseManager
{
public:
	PhaseManager() {}
	~PhaseManager() {}

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown();

private:
	// �t�F�[�Y
	BasePhase* _currentPhase;

	inline void ChangePhase(PhaseName nextPhase);
};

