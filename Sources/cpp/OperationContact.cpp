#include "../header/OperationContact.h"

OperationContact::OperationContact(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// �}�X�^�[�f�[�^�����Ɛ����m���A��Ɖ񐔂��擾
	// ���̓x�^�ł�
	operateDefaultProbability[0] = 100.0f;
	operateDefaultProbability[1] = 100.0f;
	operateDefaultProbability[2] = 100.0f;
	operateDefaultProbability[3] = 100.0f;
	operateDefaultProbability[4] = 100.0f;
}