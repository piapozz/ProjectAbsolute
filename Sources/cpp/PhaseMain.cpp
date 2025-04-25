#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/CameraController.h"
#include "../header/InputManager.h"
#include "../header/Entity_E000.h"
#include "../header/EventManager.h"

void PhaseMain::Init()
{
	// ���͂̏�����
	_pCameraController = new CameraController();
	pInputManager = new InputManager();
	pInputManager->SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	pInputManager->SetLDrackCallback([this](Vector2 pos){ this->LDrackInputProc(pos); });
	pInputManager->SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	pInputManager->SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	pInputManager->SetRDrackCallback([this](Vector2 pos){ this->RDrackInputProc(pos); });
	pInputManager->SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	pInputManager->SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	pInputManager->SetEscapeCallback([this](){ this->EscapeInputProc(); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
	BaseEntity* addEntity = new Entity_E000();
	addEntity->Init();
	_pStageManager->SetEntity(addEntity, 0);
	_pEventManager = new EventManager();
	_pEventManager->Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// ��Ƃ��I��������A�G�l���M�[��ǉ�
		_pEventManager->AddEnergy(successCount);
	};
}

bool PhaseMain::Proc()
{
	// ���͏���
	pInputManager->ExecuteCallback();
	_pCameraController->UpdateCamera();

	return false;
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

void PhaseMain::LDrackInputProc(Vector2 pos)
{

}

void PhaseMain::RDrackInputProc(Vector2 pos)
{
	_pCameraController->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ���[���h���W�ɕύX
	Vector2 worldPos = _pCameraController->GetScreen2StagePos(pos);

	// UI
	// UI�̎擾
	BaseObject* UI = ObjectManager::instance->FindPosObject(worldPos, ObjectType::UI);
	if (UI != nullptr)
	{
		UI->ClickEvent();
		return;
	}

	// �L�����N�^�[
	// �E���̎擾
	BaseObject* officer = ObjectManager::instance->FindPosObject(worldPos, ObjectType::CHARACTER);
	if (officer != nullptr)
	{
		_pPlayerOfficerList.push_back(static_cast<OfficerPlayer*>(officer));
		officer->ClickEvent();
		return;
	}

	// �X�e�[�W�̎擾
	BaseObject* section = ObjectManager::instance->FindPosObject(worldPos, ObjectType::SECTION);
	if (_pPlayerOfficerList.empty()) return;

	if (dynamic_cast<SecureRoom*>(section) != nullptr)
	{
		// ���e���̎擾
		SecureRoom* secureRoom = static_cast<SecureRoom*>(section);
		secureRoom->ClickEvent();
		secureRoom->SetInteractOfficer(_pPlayerOfficerList[0]);
	}
	// �ړ�
	if (!_pStageManager->CheckPosOnStage(worldPos)) return;
	if (!_pPlayerOfficerList[0]->GetImpossible()) return;
	_pPlayerOfficerList[0]->ChangeMoveState(worldPos);
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