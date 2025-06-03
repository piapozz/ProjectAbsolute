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

std::function<void(int)> SecureRoom::EndOperationEvent;

void SecureRoom::Init(Vector2 position, Vector2 size)
{
	BaseSection::Init(position, size);
	sectionType = SectionType::SECURE;
	layer = Layer::OBJECT;
	// 作業名も取得
	_operationNameList[0] = "世話";
	_operationNameList[1] = "観察";
	_operationNameList[2] = "接触";
	_operationNameList[3] = "危害";

	// オフセットを初期化
	Vector2 uiCenter = Vector2(0, WINDOW_HEIGHT) + Vector2(_SCREEN_UI_SIZE_X / 2, -_SCREEN_UI_SIZE_Y / 2);
	_operationUIOffsetList[0] = Vector2(-_SCREEN_UI_SIZE_X / 4, -_SCREEN_UI_SIZE_Y / 4);
	_operationUIOffsetList[1] = Vector2(_SCREEN_UI_SIZE_X / 4, -_SCREEN_UI_SIZE_Y / 4);
	_operationUIOffsetList[2] = Vector2(-_SCREEN_UI_SIZE_X / 4, _SCREEN_UI_SIZE_Y / 4);
	_operationUIOffsetList[3] = Vector2(_SCREEN_UI_SIZE_X / 4, _SCREEN_UI_SIZE_Y / 4);
	_operationCountOffset = Vector2(SECTION_SIZE_X / 2 - _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);
	_runawayCountOffset = Vector2(-SECTION_SIZE_X / 2 + _COUNT_UI_SIZE / 2, SECTION_SIZE_Y / 2 - _COUNT_UI_SIZE / 2);

	// UIの生成
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pOperationUIList[i] = new UIScreenButton();
		_pOperationUIList[i]->Init(uiCenter + _operationUIOffsetList[i], Vector2(_SCREEN_UI_SIZE_X / 2, _SCREEN_UI_SIZE_Y / 2));
		_pOperationUIList[i]->SetText(_operationNameList[i]);
		_pOperationUIList[i]->SetCallback([this, i, position]()
		{
			// UIを非表示
			for (int j = 0; j < (int)Type::MAX; j++)
			{
				_pOperationUIList[j]->SetActive(false);
			}
			_selectOperation = (Type)i;
			Vector2 setPos = Vector2(_OFFICER_OFFSET_POS_X, _OFFICER_OFFSET_POS_Y);
			_pInteractOfficer->ChangeMoveState(position + setPos, this);
		});
		_pOperationUIList[i]->SetActive(false);
	}
	_pOperationCountUI = new UIButton();
	_pOperationCountUI->Init(position + _operationCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE));
	_pOperationCountUI->SetText(std::to_string(0));
	_pOperationCountUI->SetLayer(Layer::NONE_INTERACT);
	_pRunawayCountUI = new UIButton();
	_pRunawayCountUI->Init(position + _runawayCountOffset, Vector2(_COUNT_UI_SIZE, _COUNT_UI_SIZE));
	_pRunawayCountUI->SetText(std::to_string(0));
	_pRunawayCountUI->SetLayer(Layer::NONE_INTERACT);
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
	// 待機でないなら返す
	if (_currentState != State::IDLE) return;
	_currentState = State::SELECT;

	// 作業UIの表示
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pOperationUIList[i]->SetActive(true);
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
	// 選択状態でないなら返す
	if (_currentState != State::SELECT) return;
	_currentState = State::INTERACT;
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// 作業開始イベントを発生させる
	_pEntity->StartOperationEvent();
}