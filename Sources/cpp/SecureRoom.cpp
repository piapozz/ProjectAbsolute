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

std::function<void(int)> SecureRoom::EndOperationEvent;

void SecureRoom::Init(Vector2 position, Vector2 size, LayerSetting layerSetting)
{
	BaseSection::Init(position, size, layerSetting);
	sectionType = SectionType::SECURE;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
	// 作業名も取得
	_operationNameList[0] = "世話";
	_operationNameList[1] = "観察";
	_operationNameList[2] = "接触";
	_operationNameList[3] = "危害";

	// オフセットを初期化
	_operationCountOffset = Vector2(SECTION_SIZE_X / 2 - _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);
	_runawayCountOffset = Vector2(-SECTION_SIZE_X / 2 + _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);
	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting UILayerSetting = {true, true, Layer::MIDDLE};
	_pOperationCountUI = factory.CreateWithArgs<UIButton>(position + _operationCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE), UILayerSetting);
	_pOperationCountUI->SetText(std::to_string(0));
	UILayerSetting = {true, false, Layer::MIDDLE};
	_pRunawayCountUI = factory.CreateWithArgs<UIButton>(position + _runawayCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE), UILayerSetting);
	_pRunawayCountUI->SetText(std::to_string(0));
	// エンティティーのマスターデータから作業IDを取得し生成
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
	// 選択されているなら返す
	if (_currentState == State::SELECT) return;

	// キャラクターがいないなら返す
	if (PhaseMain::GetSelectOfficerList().empty()) return;

	// 作業UIの表示
	std::vector<UIScreenButton*> pOperationUIList = UIManager::Instance().GetOperationUIList();
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		pOperationUIList[i]->SetText(_operationNameList[i]);
		pOperationUIList[i]->SetCallback([this, i, pOperationUIList]()
		{
			SetInteractOfficer(PhaseMain::GetSelectOfficerList()[0]);
			_currentState = State::SELECT;
			// UIを非表示
			for (int j = 0; j < (int)Type::MAX; j++)
			{
				pOperationUIList[j]->SetActive(false);
			}
			_selectOperation = (Type)i;
			_pInteractOfficer->ChangeMoveState(this);
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

	// メルトダウンカウントを減少させる
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// メルトダウンカウントが0になったら、エンティティーを暴走させる
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}

void SecureRoom::OperationProc()
{
	// 作業中でないなら返す
	if (_currentState != State::INTERACT) return;
	// 作業の進行、作業が終了してないなら返す
	if (!_pOperationList[(int)_selectOperation]->OperationProc()) return;
	// 作業が終了したら作業の結果を取得
	int successCount = _pOperationList[(int)_selectOperation]->GetSuccessCount();
	// エンティティの作業終了イベントを発生させる
	_pEntity->EndOperationEvent(successCount);
	// ステートを変更
	_currentState = State::IDLE;
	// 職員に終わったことを通知
	_pInteractOfficer->ChangeMoveState(_pInteractOfficer->GetPastPosition());
	// タスクを成功分増やす
	EndOperationEvent(successCount);
	//_pInteractOfficer = nullptr;
}

void SecureRoom::StartOperation()
{
	// インタラクト中でないなら
	if (_currentState == State::INTERACT) return;
	_currentState = State::INTERACT;
	_pInteractOfficer->SetPosition(position + Vector2(_OFFICER_OFFSET_POS_X, _OFFICER_OFFSET_POS_Y));
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// 作業開始イベントを発生させる
	_pEntity->StartOperationEvent();
}