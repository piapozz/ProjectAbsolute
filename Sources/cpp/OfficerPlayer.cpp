#include "../header/OfficerPlayer.h"
#include "../header/BaseCharacterState.h"
#include "../header/PhaseMain.h"
#include "../header/ObjectFactory.h"
#include "../header/OfficerController.h"
#include "../header/UIManager.h"
#include "../header/SelectorNearEntityInRoom.h"
#include "../header/AttackSingle.h"

void OfficerPlayer::Init(OfficerInitData data, int setOfficerID, Vector2 position)
{
	BaseOfficer::Init(data, setOfficerID, position);
	_groupType = CharacterGroup::OFFICER;
	_officerType = OfficerType::PLAYER;

	Transform transformWorld = transform.GetWorldTransform();
	Vector2 transformPosition = transformWorld.position;
	Vector2 transformScale = transformWorld.scale;
	Vector2 pos(transformPosition.x, transformPosition.y + (transformScale.y / 2));
	
	LayerSetting UILayerSetting = {true, false, Layer::MIDDLE};
	Transform transformUI = Transform(pos + Vector2(0, transformScale.y), Vector2(transformScale.x, transformScale.y / 4));
	slider = ObjectFactory::Instance().CreateWithArgs<UISlider>(transformUI, UILayerSetting);
	slider->SetActive(true);
	slider->SetText("HP");
	slider->SetColor(255, 0, 0);

	SetImpossible(true);
	pController = new OfficerController(this);
	
	AttackAction* normalAttack = new AttackAction();
	normalAttack->targetSelector = new SelectorNearEntityInRoom();
	normalAttack->characterAttack = new AttackSingle();
	normalAttack->attackRange = 25;

	attackActions.push_back(normalAttack);
}

void OfficerPlayer::Proc()
{
	BaseOfficer::Proc();
	pCharacterState->Update(this);
	pController->UpdateAI();
}

void OfficerPlayer::Draw()
{
	BaseOfficer::Draw();

	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	VECTOR worldPos = {position.x, position.y, 0};
	VECTOR screenPos = ConvWorldPosToScreenPos(worldPos);

	Vector2 pos(position.x, position.y + (scale.y / 2));
	slider->SetPos(pos + Vector2(0, scale.y));
	slider->SetValue((float)(health / maxHealth));
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}

void OfficerPlayer::ClickEvent()
{
	// 作業中なら何もしない
	if (stateID == CharacterStateID::OPERATION) return;
	// UIに渡す
	UIManager::Instance().SetOfficerUI(this);
	// 選択中にセットする
	std::vector<OfficerPlayer*>& selectOfficerList = PhaseMain::GetSelectOfficerList();
	selectOfficerList.clear();
	selectOfficerList.push_back(this);
}
