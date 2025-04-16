#include "../header/BaseEgoEntity.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"

void BaseEgoEntity::Init()
{
	// �G���e�B�e�B�[�̃}�X�^�[�f�[�^������ID���擾������
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperation[0] = new OperationSatisfy(entityID);
	_pOperation[1] = new OperationObserbation(entityID);
	_pOperation[2] = new OperationContact(entityID);
	_pOperation[3] = new OperationInjure(entityID);
}

void BaseEgoEntity::Proc()
{
	// �G���e�B�e�B�[�̏�Ԃɉ���������
	switch (_currentState)
	{
		case State::NONE:
		case State::IDLE:
			break;
		case State::OPERATE:
			OperationProc();
			break;
		case State::RUNAWAY:
			break;
		default:
			break;
	}
}

void BaseEgoEntity::OperationProc()
{
	// ��Ƃ̐i�s�A��Ƃ��I�����ĂȂ��Ȃ�Ԃ�
	if (!_pOperation[(int)_currentOperationType]->OperationProc()) return;
	// ��Ƃ��I���������Ƃ̌��ʂ��擾
	int successCount = _pOperation[(int)_currentOperationType]->GetSuccessCount();
	// �G���e�B�e�B�̍�ƏI���C�x���g�𔭐�������
	EndOperationEvent(successCount);
	// �X�e�[�g��ύX
	_currentState = State::IDLE;
	interactOfficerID = -1;
}

void BaseEgoEntity::StartOperation(Type operation, int operatorID)
{
	// �ҋ@��ԂłȂ��Ȃ�Ԃ�
	if (_currentState != State::IDLE) return;

	_currentState = State::OPERATE;
	_currentOperationType = operation;
	interactOfficerID = operatorID;
	_pOperation[(int)_currentOperationType]->SetOperator(operatorID);
	// ��ƊJ�n�C�x���g�𔭐�������
	StartOperationEvent();
}