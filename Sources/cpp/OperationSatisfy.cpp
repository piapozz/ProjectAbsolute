#include "../header/OperationSatisfy.h"

OperationSatisfy::OperationSatisfy(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// �}�X�^�[�f�[�^�����Ɛ����m���A��Ɖ񐔂��擾
	// ���̓x�^�ł�
	operateDefaultProbability[0] = 65.0f;
	operateDefaultProbability[1] = 65.0f;
	operateDefaultProbability[2] = 65.0f;
	operateDefaultProbability[3] = 65.0f;
	operateDefaultProbability[4] = 65.0f;
}