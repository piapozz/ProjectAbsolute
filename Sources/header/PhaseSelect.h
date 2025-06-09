#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * �I���t�F�[�Y
 */
class PhaseSelect : public BasePhase
{
public:
	PhaseSelect() {}
	~PhaseSelect() {};

	void Init() override;
	void Teardown() override {};

protected:

private:
	// �I���ł���G���e�B�e�B�[�̍ő吔
	static const int _MAX_SELECT_ENTITY = 3;
	// �I�������~�e�B�[�e�B�[��ID���X�g
	int _selectEntityIDList[_MAX_SELECT_ENTITY];

	/// <summary>
	/// �G���e�B�e�B�[��I������
	/// </summary>
	/// <param name="selectNum"></param>
	void SelectEntity(int selectNum);
};

