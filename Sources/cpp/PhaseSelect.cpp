#include "../header/PhaseSelect.h"

void SelectEntity(int selectNum);

void PhaseSelect::Init()
{
	// ���͎�t�N���X�𐶐�


	// �I������������
	for (int i = 0; i < _MAX_SELECT_ENTITY; i++)
	{
		// �G���e�B�e�B�[�̃v�[�����珊�����Ă��Ȃ��G���e�B�e�B�[�𔲂��o��
		// �����_���ȃG���e�B�e�B�[��ǉ�����
		_selectEntityIDList[i] = -1;
	}

	// ���X�g�ɉ�����UI�𐶐�

}

void PhaseSelect::SelectEntity(int selectNum)
{
	
}