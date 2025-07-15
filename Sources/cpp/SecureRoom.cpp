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
#include "../header/PhaseMain.h"
#include "../header/ObjectFactory.h"
#include "../header/UIEntity.h"
#include "../header/UIText.h"
#include "../header/EventManager.h"
#include "../header/SelectOperationUI.h"

std::function<void()> SecureRoom::StartOperationEvent;
std::function<void(int)> SecureRoom::EndOperationEvent;
// 表示するUIを取得するコールバック
std::function<UIEntity*(void)> SecureRoom::GetUIEntityCallback;
std::function<SelectOperationUI*(void)> SecureRoom::GetUIOperationCallback;

void SecureRoom::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseSection::Init(setTransform, layerSetting);
	sectionType = SectionType::SECURE;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
	// 作業名も取得
	_operationNameList[0] = "世話";
	_operationNameList[1] = "観察";
	_operationNameList[2] = "接触";
	_operationNameList[3] = "危害";
	_currentState = State::IDLE;

	// UI生成
	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting UILayerSetting = {true, false, Layer::FRONT};

	worldTransform = Transform(_OPERATION__COUNT_UI_POS, _COUNT_UI_SCALE, this);
	_pOperationCountUI = factory.CreateWithArgs<UIButton>(worldTransform, UILayerSetting);
	_pOperationCountUI->SetText(std::to_string(0));
	_pOperationCountUI->SetFontSize(_COUNT_UI_FONT_SIZE);
	worldTransform = Transform(_MELTDOWN_COUNT_UI_POS, _COUNT_UI_SCALE, this);
	_pRunawayCountUI = factory.CreateWithArgs<UIButton>(worldTransform, UILayerSetting);
	_pRunawayCountUI->SetText(std::to_string(0));
	_pRunawayCountUI->SetFontSize(_COUNT_UI_FONT_SIZE);
	worldTransform = Transform(_NAME_UI_POS, _NAME_UI_SCALE, this);
	UILayerSetting.m_interact = true;
	_pInformationUI = factory.CreateWithArgs<UIButton>(worldTransform, UILayerSetting);
	_pInformationUI->SetCallback([this]()
	{
		GetUIEntityCallback()->SetActive(true);
	});
	UILayerSetting = {false, false, Layer::FRONT};
	_pMeltText = factory.CreateWithArgs<UIText>(setTransform, UILayerSetting);
	_pMeltText->SetText("メルトダウン");

	// エンティティーのマスターデータから作業IDを取得し生成
	// 現在は固定で生成
	int entityID = 0;
	_pOperationList[0] = new OperationSatisfy(entityID, _pOperationCountUI);
	_pOperationList[1] = new OperationObserbation(entityID, _pOperationCountUI);
	_pOperationList[2] = new OperationContact(entityID, _pOperationCountUI);
	_pOperationList[3] = new OperationInjure(entityID, _pOperationCountUI);
}

void SecureRoom::Proc()
{
	OperationProc();
	MeltdownProc();
}

void SecureRoom::Draw()
{
	BaseSection::Draw();

	// UIの描画
	_pOperationCountUI->Draw();
	_pRunawayCountUI->Draw();
	_pInformationUI->Draw();
}

void SecureRoom::Teardown()
{

}

void SecureRoom::ClickEvent()
{
	// 選択されているなら返す
	if (_currentState != State::IDLE) return;

	// キャラクターがいないなら返す
	if (PhaseMain::GetSelectOfficerList().empty()) return;

	// 作業UIの表示
	SelectOperationUI* operationUI = GetUIOperationCallback();
	operationUI->SetActive(true);
	std::vector<UIScreenButton*> operationList = operationUI->GetOperationUIList();
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		operationList[i]->SetText(_operationNameList[i]);
		operationList[i]->SetCallback([this, i, operationUI]()
		{
			SetInteractOfficer(PhaseMain::GetSelectOfficerList()[0]);
			_currentState = State::SELECT;
			// UIを非表示
			operationUI->SetActive(false);
			// 選択された作業を設定
			_selectOperation = (Type)i;
			// 作業に向かわせる
			_pInteractOfficer->ChangeMoveState(this);
		});
	}
}

void SecureRoom::SetEntity(BaseEntity* setEntity)
{
	_pEntity = setEntity;
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	_pEntity->SetPosition(position + GetScale() / 2.0f * _ENTITY_OFFSET);
	_pEntity->SetRunawayUI(_pRunawayCountUI);
	// マスターから名前取得
	_pInformationUI->SetText("Triangle");
	_pEntity->SetRunawayCallback([this]()
	{
		_currentState = State::RUNAWAY;
	});
	_pEntity->SetDeadEventCallBack([this]()
	{
		ReplaceEntity();
	});
}

void SecureRoom::StartMeltdown()
{
	// 脱走中ならメルトダウンしない
	if (_currentState == State::RUNAWAY) return;

	_isMeltdown = true;
	_meltdownCount = _MELTDOWN_COUNT;
	_pMeltText->SetActive(true);
}

void SecureRoom::MeltdownProc()
{
	if (!_isMeltdown) return;

	// 途中で脱走した場合はメルトダウン解除
	if (_currentState == State::RUNAWAY)
	{
		_pMeltText->SetActive(false);
		_isMeltdown = false;
	}
	// メルトダウンカウントを減少させる
	_meltdownCount--;
	_pMeltText->SetText("メルトダウン" + std::to_string(_meltdownCount));

	if (_meltdownCount > 0) return;
	_pMeltText->SetActive(false);

	// メルトダウンカウントが0になったら、エンティティーを暴走させる
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
	_currentState = State::RUNAWAY;
	_isMeltdown = false;
}

void SecureRoom::OperationProc()
{
	// 作業中でないなら返す
	if (_currentState != State::INTERACT) return;
	// 作業の進行、作業が終了してないなら返す
	if (!_pOperationList[(int)_selectOperation]->OperationProc()) return;
	// ステートを変更
	_currentState = State::IDLE;
	// 作業が終了したら作業の結果を取得
	int successCount = _pOperationList[(int)_selectOperation]->GetSuccessCount();
	// エンティティの作業終了イベントを発生させる
	_pEntity->EndOperationEvent(successCount);
	// 職員に終わったことを通知
	_pInteractOfficer->ChangeMoveState(_pInteractOfficer->GetPastPosition());
	// タスクを成功分増やす
	EndOperationEvent(successCount);
	_pInteractOfficer = nullptr;
}

void SecureRoom::StartOperation()
{
	// インタラクト中でないなら
	if (_currentState == State::INTERACT) return;
	_currentState = State::INTERACT;
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	_pInteractOfficer->SetPosition(position + GetScale() / 2.0f * _OFFICER_OFFSET);
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// 作業開始イベントを発生させる
	_pEntity->StartOperationEvent();
	// メルトダウンカウンターを増加させる
	EventManager::Instance().AddMelt();
}

void SecureRoom::ReplaceEntity()
{
	_pEntity->SetPosition(transform.GetWorldTransform().position + GetScale() / 2.0f * _ENTITY_OFFSET);
	_currentState = State::IDLE;
	_pEntity->Respawn();
}