#include "../header/BaseOperation.h"

BaseOperation::BaseOperation(int masterEntityID)
{
	// ��Ə�Ԃ̏�����
	_operationResultList = std::vector<Result>(operateCount, Result::Invalid);
}

bool BaseOperation::OperationProc()
{
	// ��Ƃ̐i�s
	_frameCounter++;
	// ��Ƃ���t���[���ɂȂ����珈��
	if (_currentSpeed <= _frameCounter) return false;
	_currentOperationCount++;
	// ��Ƃ̐����������_���Ɍ��߂�
	bool result = _currentProbability * 10 <= GetRand(1000);
	if (result)
	{
		// ���s
		// �_���[�W��^����

		// ���s���L�^
		_operationResultList[_currentOperationCount - 1] = Result::Failure;
	}
	else
	{
		// ����
		_operationResultList[_currentOperationCount - 1] = Result::Success;
	}

	_frameCounter = 0;
	// �I�����m�F
	if (_currentOperationCount < operateCount) return false;

	return true;
}

void BaseOperation::SetOperator(int _operatorID)
{
	// ��Ǝ҂�ID���烌�x���ƃp�����[�^�[���擾
	// ���̓x�^�ł�
	_operatorLevel = 1;
	_operatorParameter = 30;
	_currentSpeed = _DEFAULT_OPERATE_FRAME - (int)(_DEFAULT_OPERATE_FRAME / 2 * _OPERATE_SPEED_RATIO * _operatorParameter);
	_currentProbability = operateDefaultProbability[_operatorLevel - 1] + _OPERATE_PROBABILITY_RATIO * _operatorParameter;
	_frameCounter = 0;
	_currentOperationCount = 0;
}

int BaseOperation::GetSuccessCount()
{
	// ��Ƃ̌��ʂ��擾
	int result = 0;
	for (int i = 0; i < operateCount; i++)
	{
		if (_operationResultList[i] == Result::Success) result++;
	}
	return result;
}