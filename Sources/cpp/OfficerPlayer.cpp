#include "../header/OfficerPlayer.h"
#include "../header/BaseCharacterState.h"
#include "../header/PhaseMain.h"
#include "../header/ObjectFactory.h"
#include "../header/OfficerController.h"
#include "../header/UIManager.h"
#include "../header/SelectorNearEntityInRoom.h"
#include "../header/AttackSingle.h"
#include "../header/UIOfficer.h"

std::function<UIOfficer*(void)> OfficerPlayer::GetUIOfficerCallback;

void OfficerPlayer::Init(OfficerInitData data, int setOfficerID, Vector2 position)
{
	BaseOfficer::Init(data, setOfficerID, position);
	_groupType = CharacterGroup::OFFICER;
	_officerType = OfficerType::PLAYER;

	Transform transformWorld = transform.GetWorldTransform();
	Vector2 transformPosition = transformWorld.position;
	Vector2 transformScale = transformWorld.scale;
	Vector2 pos(transformPosition.x, transformPosition.y + (transformScale.y / 2));
	
	Vector2 parentScale = Vector2(transform.GetWorldTransform().scale.x, transform.GetWorldTransform().scale.y);
	LayerSetting UILayerSetting = {true, false, Layer::FRONT};
	Transform transformUI = Transform(Vector2(0, 2.7f), Vector2(1.0f, 0.15f), this);
	healthSlider = ObjectFactory::Instance().CreateWithArgs<UISlider>(transformUI, UILayerSetting);
	healthSlider->SetActive(true);
	healthSlider->SetColor(255, 0, 0);

	transformUI = Transform(Vector2(0, 2.5f), Vector2(1.0f, 0.15f), this);
	mentalSlider = ObjectFactory::Instance().CreateWithArgs<UISlider>(transformUI, UILayerSetting);
	mentalSlider->SetActive(true);
	mentalSlider->SetColor(255, 255, 255);

	SetImpossible(true);
	pController = new OfficerController(this);
	pController->isFreeze = false;

	AttackAction* normalAttack = new AttackAction();
	normalAttack->targetSelector = new SelectorNearEntityInRoom();
	normalAttack->characterAttack = new AttackSingle();
	normalAttack->attackRange = 10;

	attackActions.push_back(normalAttack);
}

void OfficerPlayer::Proc()
{
	BaseOfficer::Proc();
	pCharacterState->Update(this);
	pController->UpdateAI();
	healthSlider->Proc();
	mentalSlider->Proc();
}

void OfficerPlayer::Draw()
{
	BaseOfficer::Draw();

	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	VECTOR worldPos = {position.x, position.y, 0};
	VECTOR screenPos = ConvWorldPosToScreenPos(worldPos);

	float value = (float)health / (float)maxHealth;
	healthSlider->SetValue(value);
	healthSlider->Draw();
	value = (float)_mental / (float)_maxMental;
	mentalSlider->SetValue(value);
	mentalSlider->Draw();
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
	GetUIOfficerCallback()->SetOfficer(*static_cast<BaseOfficer*>(this));
	// 選択中にセットする
	std::vector<OfficerPlayer*>& selectOfficerList = PhaseMain::GetSelectOfficerList();
	selectOfficerList.clear();
	selectOfficerList.push_back(this);
}
