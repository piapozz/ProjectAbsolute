#include "../header/SecureRoom.h"
#include "../header/BaseEntity.h"
#include "../header/ObjectManager.h"
#include "../header/UIButton.h"
#include "../header/BaseOperation.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"
#include "../header/OfficerPlayer.h"

void SecureRoom::Init(Vector2 position, Vector2 size)
{
	BaseSection::Init(position, size);
	sectionType = SectionType::SECURE;
	layer = Layer::OBJECT;
	// �G���e�B�e�B�[�̃}�X�^�[�f�[�^������ID���擾������
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperationList[0] = new OperationSatisfy(entityID);
	_pOperationList[1] = new OperationObserbation(entityID);
	_pOperationList[2] = new OperationContact(entityID);
	_pOperationList[3] = new OperationInjure(entityID);
	// ��Ɩ����擾
	_operationNameList[0] = "���b";
	_operationNameList[1] = "�ώ@";
	_operationNameList[2] = "�ڐG";
	_operationNameList[3] = "��Q";

	// UI�̃I�t�Z�b�g��������
	_operationUIOffsetList[0] = Vector2(-SECTION_SIZE / 4, SECTION_SIZE / 4);
	_operationUIOffsetList[1] = Vector2(SECTION_SIZE / 4, SECTION_SIZE / 4);
	_operationUIOffsetList[2] = Vector2(-SECTION_SIZE / 4, -SECTION_SIZE / 4);
	_operationUIOffsetList[3] = Vector2(SECTION_SIZE / 4, -SECTION_SIZE / 4);

	// UI�̐���
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pButtonList[i] = new UIButton();
		_pButtonList[i]->Init(position + _operationUIOffsetList[i], Vector2(SECTION_SIZE / 2, SECTION_SIZE / 2));
		_pButtonList[i]->SetButtonText(_operationNameList[i]);
		_pButtonList[i]->SetCallback([this, i, position]()
		{ 
			_selectOperation = (Type)i;
			_pInteractOfficer->ChangeMoveState(position, this);
		});
		_pButtonList[i]->SetActive(false);
		ObjectManager::AddObject(_pButtonList[i]);
	}
}

void SecureRoom::Proc()
{
	MeltdownProc();
}

void SecureRoom::Draw()
{
	BaseSection::Draw();
}

void SecureRoom::Teardown()
{
	
}

void SecureRoom::ClickEvent()
{
	// ���UI�̕\��
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pButtonList[i]->SetActive(true);
	}
}

void SecureRoom::StartMeltdown()
{
	_isMeltdown = true;
	_meltdownCount = _MELTDOWN_COUNT;
}

void SecureRoom::MeltdownProc()
{
	if (!_isMeltdown || !CanMeltdown()) return;

	// �����g�_�E���J�E���g������������
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// �����g�_�E���J�E���g��0�ɂȂ�����A�G���e�B�e�B�[��\��������
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}

int SecureRoom::OperationProc()
{
	// ��Ƃ̐i�s�A��Ƃ��I�����ĂȂ��Ȃ�Ԃ�
	if (!_pOperationList[(int)_selectOperation]->OperationProc()) return -1;
	// ��Ƃ��I���������Ƃ̌��ʂ��擾
	int successCount = _pOperationList[(int)_selectOperation]->GetSuccessCount();
	// �G���e�B�e�B�̍�ƏI���C�x���g�𔭐�������
	_pEntity->EndOperationEvent(successCount);
	// �X�e�[�g��ύX
	_currentState = State::IDLE;
	_pInteractOfficer = nullptr;

	return successCount;
}

void SecureRoom::StartOperation()
{
	// �ҋ@��ԂłȂ��Ȃ�Ԃ�
	if (_currentState != State::IDLE) return;

	_currentState = State::INTERACT;
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// ��ƊJ�n�C�x���g�𔭐�������
	_pEntity->StartOperationEvent();
}