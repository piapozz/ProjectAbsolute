#pragma once
#include <vector>
#include "PhaseSelect.h"
#include "PhaseStandby.h"
#include "PhaseMain.h"
#include "PhaseResult.h"

/*
 * Sakakura
 * �t�F�[�Y�Ǘ��N���X
 */
class PhaseManager
{
public:
	inline PhaseManager() { Init(); }
	~PhaseManager() { Teardown(); }

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// ����
	/// </summary>
	void Proc();
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown();

private:
	// �t�F�[�Y�̃��X�g
	std::vector<BasePhase*> _phaseList;
};

