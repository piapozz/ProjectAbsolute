#include "../header/OperationInjure.h"

OperationInjure::OperationInjure(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI)
{
	// �}�X�^�[�f�[�^�����Ɛ����m���A��Ɖ񐔂��擾
	// ���̓x�^�ł�
	operateCount = 10;
	operateDefaultProbability[0] = 50.0f;
	operateDefaultProbability[1] = 30.0f;
	operateDefaultProbability[2] = 10.0f;
	operateDefaultProbability[3] = 5.0f;
	operateDefaultProbability[4] = 1.0f;
}
