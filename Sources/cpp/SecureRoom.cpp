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
			CountMeltdown();
			break;
		case State::OPERATE:
			// ��Ƃ̎�ނɉ���������
			OperationProc();
			break;
		case State::EMERGENCY:
			break;
		case State::USE:
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
	// �c�[���^�Ȃ�Ԃ�
	BaseToolEntity* pToolEntity = dynamic_cast<BaseToolEntity*>(_pEntity);
	if (pToolEntity != nullptr) return;

	// �ҋ@��ԂłȂ��Ȃ�Ԃ�
	if (_currentState != State::IDLE) return;

	_currentState = State::OPERATE;
	_currentOperationType = operation;
	_pOperation[(int)_currentOperationType]->SetOperator(operatorID);
	// �G���e�B�e�B�̍�ƊJ�n�C�x���g�𔭐�������
	_pEntity->StartOperationEvent();
}

void SecureRoom::StartMeltdown()
{
	_isMeltdown = true;
	_meltdownCount = _MELTDOWN_COUNT;
}

void SecureRoom::OperationProc()
{
	// ��Ƃ̐i�s�A��Ƃ��I�����ĂȂ��Ȃ�Ԃ�
	if (!_pOperation[(int)_currentState]->OperationProc()) return;

	// ��Ƃ��I���������Ƃ̌��ʂ��擾
	int successCount = _pOperation[(int)_currentState]->GetSuccessCount();
	// �G���e�B�e�B�̍�ƏI���C�x���g�𔭐�������
	_pEntity->EndOperationEvent(successCount);
	// ��ƈ��̃p�����[�^�[�𑝉�������
	
}

void SecureRoom::CountMeltdown()
{
	if (!_isMeltdown) return;

	// �����g�_�E���J�E���g������������
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// �����g�_�E���J�E���g��0�ɂȂ�����A�G���e�B�e�B�[��\��������
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}