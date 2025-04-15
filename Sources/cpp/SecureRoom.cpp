#include "../header/SecureRoom.h"

void SecureRoom::Init()
{
	// �G���e�B�e�B�[�̃}�X�^�[�f�[�^������ID���擾������
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperation[0] = new OperationSatisfy(entityID);
	_pOperation[1] = new OperationObserbation(entityID);
	_pOperation[2] = new OperationContact(entityID);
	_pOperation[3] = new OperationInjure(entityID);
}

void SecureRoom::Proc()
{
	// ���e���̏�Ԃɉ���������
	switch (_currentState)
	{
		case State::NONE:
		case State::IDLE:
			break;
		case State::OPERATE:
			// ��Ƃ̎�ނɉ���������
			OperationProc();
			break;
		case State::EMERGENCY:
			break;
		default:
			break;
	}
}

void SecureRoom::Draw()
{

}

void SecureRoom::Teardown()
{

}

void SecureRoom::StartOperation(Type operation, int operatorID)
{
	_currentState = State::OPERATE;
	_currentOperationType = operation;
	_pOperation[(int)_currentState]->SetOperator(operatorID);
}

void SecureRoom::OperationProc()
{
	// ��Ƒ��x�ɉ����č�Ƃ�i�߂�
	if (!_pOperation[(int)_currentState]->OperationProc()) return;

	// ��Ƃ��I���������Ƃ̌��ʂ��擾
	int successCount = _pOperation[(int)_currentState]->GetSuccessCount();
	// ��ƈ��̃p�����[�^�[�𑝉�������
	
	// ��Ƃ̌��ʂ��G���e�B�e�B�[�ɒʒm

}