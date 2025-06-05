#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"
#include "../header/Entity_E000.h"
#include "../header/EventManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIManager.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"
#include "../header/ObjectFactory.h"

std::vector<OfficerPlayer*>& PhaseMain::GetSelectOfficerList(){ return _pSelectOfficerList; }
std::vector<OfficerPlayer*> PhaseMain::_pSelectOfficerList;

void PhaseMain::Init()
{
	// ���͂̏�����
	_pCameraController = new CameraController();
	pInputManager = new InputManager();
	pInputManager->SetOnCursorCallback([this](Vector2 pos){ this->OnCursorProc(pos); });
	pInputManager->SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	pInputManager->SetLDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->LDrackInputProc(pos, oldPos); });
	pInputManager->SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	pInputManager->SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	pInputManager->SetRDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->RDrackInputProc(pos, oldPos); });
	pInputManager->SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	pInputManager->SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	pInputManager->SetEscapeCallback([this](){ this->EscapeInputProc(); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
	BaseEntity* addEntity = ObjectFactory::Instance().Create<Entity_E000>();
	_pStageManager->SetEntity(addEntity, 0);
	_pEventManager = new EventManager();
	_pEventManager->Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// ��Ƃ��I��������A�G�l���M�[��ǉ�
		_pEventManager->AddEnergy(successCount);
	};
	_pRangeSelect = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(Vector2::zero(), Vector2::zero(), false);
	_pRangeSelect->SetLayer(Layer::NONE_DRAW);
	_pUIManager = new UIManager();
	// �e�I�u�W�F�N�g�̃C���^���N�g���̃R�[���o�b�N�ݒ�

}

bool PhaseMain::Proc()
{
	// ���͏���
	pInputManager->ExecuteCallback();
	_pCameraController->UpdateCamera();

	return false;
}

void PhaseMain::OnCursorProc(Vector2 pos)
{
	// �ȑO����Ă����I�u�W�F�N�g������Ă��Ȃ�����
	BaseObject* onCursorObj = pInputManager->GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// ���[���h���W�ɕύX
	Vector2 worldPos = _pCameraController->GetScreen2StagePos(pos);

	// �X�N���[��UI
	// UI�̎擾
	BaseObject* ScreenUI = ObjectManager::Instance().FindPosObject(pos);
	if (ScreenUI != nullptr)
	{
		ScreenUI->OnCursor();
		pInputManager->SetOnCursorObject(ScreenUI);
		return;
	}
}

void PhaseMain::LPushInputProc(Vector2 pos)
{
	// UI�̓���


	// �L�����N�^�[�̓���


	// �X�e�[�W�̓���

}

void PhaseMain::RPushInputProc(Vector2 pos)
{
	// �J�����̈ړ�
	_pCameraController->RPushEvent(pos);
	// �L�����N�^�[���I������Ă��邩�ŕ���

}

void PhaseMain::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	if (pInputManager->IsLeftClick(pos)) return;
	// �͈͑I��
	_pRangeSelect->SetLayer(Layer::NONE_INTERACT);
	_pRangeSelect->SetPosition(pos + ((oldPos - pos) / 2));
	_pRangeSelect->SetSize(oldPos - pos);
}

void PhaseMain::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	_pCameraController->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ���[���h���W�ɕύX
	Vector2 worldPos = _pCameraController->GetScreen2StagePos(pos);

	// �N���b�N�������ꂽ�Ȃ�
	if (pInputManager->IsLeftClick(pos))
	{
		// �X�N���[��UI
		BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
		// �X�N���[��UI���Ȃ��Ȃ烏�[���h���W��n���ăI�u�W�F�N�g�擾
		if (object == nullptr)
		{
			object = ObjectManager::Instance().FindPosObject(worldPos);
		}
		if (object != nullptr)
		{
			object->ClickEvent();
			return;
		}
		// �X�e�[�W�O���N���b�N
		if (!_pStageManager->CheckPosOnStage(worldPos))
		{
			_pSelectOfficerList.clear();
			_pUIManager->SetActiveOperationUI(false);

			return;
		}
	}
	// �h���b�N�������ꂽ�Ȃ�
	else
	{
		_pRangeSelect->SetLayer(Layer::NONE_DRAW);
		// ���[���h���W�ɕύX
		Vector2 worldOldPos = _pCameraController->GetScreen2StagePos(oldPos);
		// ���S���W�Ƒ傫�����w��
		Vector2 centorPos = Vector2(worldPos + ((worldOldPos - worldPos) / 2));
		Vector2 size = worldOldPos - worldPos;
		// �E���̎擾
		std::vector<BaseObject*> officerList = ObjectManager::Instance().FindRectAllObject(centorPos, size, ObjectType::CHARACTER);
		if (officerList.empty()) return;
		_pSelectOfficerList.clear();
		for (int i = 0, max = officerList.size(); i < max; i++)
		{
			OfficerPlayer* officer = static_cast<OfficerPlayer*>(officerList[i]);
			_pSelectOfficerList.push_back(officer);
			officer->ClickEvent();
		}
		return;
	}
}

void PhaseMain::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseMain::WheelRotInputProc(Vector2 pos, int rot)
{
	_pCameraController->WheelEvent(rot);
}

void PhaseMain::EscapeInputProc()
{

}