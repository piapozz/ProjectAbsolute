#include "../header/OperationInjure.h"

OperationInjure::OperationInjure(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// �}�X�^�[�f�[�^�����Ɛ����m���A��Ɖ񐔂��擾
	// ���̓x�^�ł�
	operateDefaultProbability[0] = 40.0f;
	operateDefaultProbability[1] = 40.0f;
	operateDefaultProbability[2] = 40.0f;
	operateDefaultProbability[3] = 40.0f;
	operateDefaultProbability[4] = 40.0f;
}
