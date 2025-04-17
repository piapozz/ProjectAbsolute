#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * �I���t�F�[�Y
 */
class PhaseSelect : public BasePhase
{
public:
	PhaseSelect() { Init(); }
	~PhaseSelect() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void LClickInputProc(Vector2 pos, Vector2 oldPos) override;

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

