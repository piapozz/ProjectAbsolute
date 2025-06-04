#include "../header/SecureRoom.h"
#include "../header/BaseEntity.h"
#include "../header/ObjectManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIButton.h"
#include "../header/BaseOperation.h"
#include "../header/OperationSatisfy.h"
#include "../header/OperationObserbation.h"
#include "../header/OperationContact.h"
#include "../header/OperationInjure.h"
#include "../header/OfficerPlayer.h"
#include "../header/UIManager.h"

std::function<void(int)> SecureRoom::EndOperationEvent;

void SecureRoom::Init(Vector2 position, Vector2 size)
{
	BaseSection::Init(position, size);
	sectionType = SectionType::SECURE;
	layer = Layer::OBJECT;
	// ��Ɩ����擾
	_operationNameList[0] = "���b";
	_operationNameList[1] = "�ώ@";
	_operationNameList[2] = "�ڐG";
	_operationNameList[3] = "��Q";

	// �I�t�Z�b�g��������
	_operationCountOffset = Vector2(SECTION_SIZE_X / 2 - _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);
	_runawayCountOffset = Vector2(-SECTION_SIZE_X / 2 + _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);

	_pOperationCountUI = new UIButton();
	_pOperationCountUI->Init(position + _operationCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE));
	_pOperationCountUI->SetText(std::to_string(0));
	_pOperationCountUI->SetLayer(Layer::NONE_INTERACT);
	_pRunawayCountUI = new UIButton();
	_pRunawayCountUI->Init(position + _runawayCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE));
	_pRunawayCountUI->SetText(std::to_string(0));
	_pRunawayCountUI->SetLayer(Layer::NONE_INTERACT);
	// �G���e�B�e�B�[�̃}�X�^�[�f�[�^������ID���擾������
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperationList[0] = new OperationSatisfy(entityID, _pOperationCountUI);
	_pOperationList[1] = new OperationObserbation(entityID, _pOperationCountUI);
	_pOperationList[2] = new OperationContact(entityID, _pOperationCountUI);
	_pOperationList[3] = new OperationInjure(entityID, _pOperationCountUI);
}

void SecureRoom::Proc()
{
	MeltdownProc();
	OperationProc();
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
	// �ҋ@�łȂ��Ȃ�Ԃ�
	if (_currentState != State::IDLE) return;
	_currentState = State::SELECT;

	// ���UI�̕\��
	std::vector<UIScreenButton*> pOperationUIList = UIManager::GetOperationUIList();
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		pOperationUIList[i]->SetText(_operationNameList[i]);
		pOperationUIList[i]->SetCallback([this, i, pOperationUIList]()
		{
			// UI���\��
			for (int j = 0; j < (int)Type::MAX; j++)
			{
				pOperationUIList[j]->SetActive(false);
			}
			_selectOperation = (Type)i;
			Vector2 setPos = position + Vector2(_OFFICER_OFFSET_POS_X, _OFFICER_OFFSET_POS_Y);
			_pInteractOfficer->ChangeMoveState(setPos, this);
		});
		pOperationUIList[i]->SetActive(true);
	}
}

void SecureRoom::SetEntity(BaseEntity* setEntity)
{
	_pEntity = setEntity;
	_pEntity->SetPosition(position + Vector2(_ENTITY_OFFSET_POS_X, _ENTITY_OFFSET_POS_Y));
	_pEntity->SetRunawayUI(_pRunawayCountUI);
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

void SecureRoom::OperationProc()
{
	// ��ƒ��łȂ��Ȃ�Ԃ�
	if (_currentState != State::INTERACT) return;
	// ��Ƃ̐i�s�A��Ƃ��I�����ĂȂ��Ȃ�Ԃ�
	if (!_pOperationList[(int)_selectOperation]->OperationProc()) return;
	// ��Ƃ��I���������Ƃ̌��ʂ��擾
	int successCount = _pOperationList[(int)_selectOperation]->GetSuccessCount();
	// �G���e�B�e�B�̍�ƏI���C�x���g�𔭐�������
	_pEntity->EndOperationEvent(successCount);
	// �X�e�[�g��ύX
	_currentState = State::IDLE;
	// �E���ɏI��������Ƃ�ʒm
	_pInteractOfficer->ChangeMoveState(_pInteractOfficer->GetPastPosition());
	// �^�X�N�𐬌������₷
	EndOperationEvent(successCount);
	//_pInteractOfficer = nullptr;
}

void SecureRoom::StartOperation()
{
	// �I����ԂłȂ��Ȃ�Ԃ�
	if (_currentState != State::SELECT) return;
	_currentState = State::INTERACT;
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// ��ƊJ�n�C�x���g�𔭐�������
	_pEntity->StartOperationEvent();
}