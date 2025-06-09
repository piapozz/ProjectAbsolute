#include "../header/PhaseMain.h"
#include "../header/StageManager.h"
#include "../header/OfficerManager.h"
#include "../header/Camera.h"
#include "../header/InputManager.h"
#include "../header/Entity_E000.h"
#include "../header/EventManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIManager.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"
#include "../header/ObjectFactory.h"
#include "../header/CommonModule.h"

std::vector<OfficerPlayer*>& PhaseMain::GetSelectOfficerList(){ return _pSelectOfficerList; }
std::vector<OfficerPlayer*> PhaseMain::_pSelectOfficerList;

void PhaseMain::Init()
{
	// ���͂̏�����
	InputManager& inputManager = InputManager::Instance();
	inputManager.SetOnCursorCallback([this](Vector2 pos){ this->OnCursorProc(pos); });
	inputManager.SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	inputManager.SetLDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->LDrackInputProc(pos, oldPos); });
	inputManager.SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	inputManager.SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	inputManager.SetRDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->RDrackInputProc(pos, oldPos); });
	inputManager.SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	inputManager.SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	inputManager.SetEscapeCallback([this](){ this->EscapeInputProc(); });

	_pStageManager = new StageManager();
	_pStageManager->SetStageData(_stageData);
	_pStageManager->CreateStage();
	_pOfficerManager = new OfficerManager();
	_pOfficerManager->Init();
	LayerSetting layerSetting = {true, false, Layer::MIDDLE};
	BaseEntity* addEntity = ObjectFactory::Instance().CreateWithArgs<Entity_E000>(layerSetting);
	_pStageManager->SetEntity(addEntity, 0);
	_pEventManager = new EventManager();
	_pEventManager->Init();
	SecureRoom::EndOperationEvent = [this](int successCount)
	{
		// ��Ƃ��I��������A�G�l���M�[��ǉ�
		_pEventManager->AddEnergy(successCount);
	};
	layerSetting = {true, false, Layer::FRONT};
	_pRangeSelect = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(Vector2::zero(), Vector2::zero(), false, layerSetting);
	_pUIManager = new UIManager();
	// �J��������
	_pCamera = new Camera();
	// �e�I�u�W�F�N�g�̃C���^���N�g���̃R�[���o�b�N�ݒ�

}

void PhaseMain::OnCursorProc(Vector2 pos)
{
	// �ȑO����Ă����I�u�W�F�N�g������Ă��Ȃ�����
	BaseObject* onCursorObj = InputManager::Instance().GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// ���[���h���W�ɕύX
	Camera* camera = Camera::instance;
	Vector2 worldPos =  GetScreen2StagePos(pos, camera->GetHeight(), camera->GetPosition());

	// �X�N���[��UI
	// UI�̎擾
	BaseObject* ScreenUI = ObjectManager::Instance().FindPosObject(pos);
	if (ScreenUI != nullptr)
	{
		ScreenUI->OnCursor();
		InputManager::Instance().SetOnCursorObject(ScreenUI);
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
	_pCamera->RPushEvent(pos);
	// �L�����N�^�[���I������Ă��邩�ŕ���

}

void PhaseMain::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	if (InputManager::Instance().IsLeftClick(pos)) return;
	// �͈͑I��
	_pRangeSelect->SetActive(true);
	_pRangeSelect->SetPosition(pos + ((oldPos - pos) / 2));
	_pRangeSelect->SetSize(oldPos - pos);
}

void PhaseMain::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
	_pCamera->RDrackEvent(pos);
}

void PhaseMain::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// ���[���h���W�ɕύX
	Camera* camera = Camera::instance;
	Vector2 worldPos =  GetScreen2StagePos(pos, camera->GetHeight(), camera->GetPosition());

	// �N���b�N�������ꂽ�Ȃ�
	if (InputManager::Instance().IsLeftClick(pos))
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
		_pRangeSelect->SetActive(false);
		// ���[���h���W�ɕύX
		Camera* camera = Camera::instance;
		Vector2 worldOldPos =  GetScreen2StagePos(oldPos, camera->GetHeight(), camera->GetPosition());
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
	_pCamera->WheelEvent(rot);
}

void PhaseMain::EscapeInputProc()
{

}