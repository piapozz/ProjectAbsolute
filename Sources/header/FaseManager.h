#pragma once
#include <vector>
#include "FaseSelect.h"
#include "FaseStandby.h"
#include "FaseMain.h"
#include "FaseResult.h"

/*
 * Sakakura
 * �t�F�[�Y�Ǘ��N���X
 */
class FaseManager
{
public:
	inline FaseManager() { Init(); }
	~FaseManager() { Teardown(); }

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
	std::vector<BaseFase*> _faseList;
};

