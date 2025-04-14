#include "../header/SecureRoom.h"

void SecureRoom::Init()
{
	// _pOperation = new Operation(_pEntity->GetID());
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
	// �`��
	BaseSection::Draw();
}

void SecureRoom::Teardown()
{
	// �j��
	BaseSection::Teardown();
}

void SecureRoom::SetState(State setState)
{
	// �X�e�[�g��؂�ւ���
	_currentState = setState;
}

void SecureRoom::OperationProc()
{
	// ��Ƒ��x�ɉ����č�Ƃ�i�߂�
	
}