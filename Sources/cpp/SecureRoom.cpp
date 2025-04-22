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
	// エンティティーのマスターデータから作業IDを取得し生成
	// _pOperation = new Operation(_pEntity->GetID());
	int entityID = 0;
	_pOperationList[0] = new OperationSatisfy(entityID);
	_pOperationList[1] = new OperationObserbation(entityID);
	_pOperationList[2] = new OperationContact(entityID);
	_pOperationList[3] = new OperationInjure(entityID);
	// 作業名も取得
	_operationNameList[0] = "世話";
	_operationNameList[1] = "観察";
	_operationNameList[2] = "接触";
	_operationNameList[3] = "危害";

	// UIのオフセットを初期化
	_operationUIOffsetList[0] = Vector2(-SECTION_SIZE / 4, SECTION_SIZE / 4);
	_operationUIOffsetList[1] = Vector2(SECTION_SIZE / 4, SECTION_SIZE / 4);
	_operationUIOffsetList[2] = Vector2(-SECTION_SIZE / 4, -SECTION_SIZE / 4);
	_operationUIOffsetList[3] = Vector2(SECTION_SIZE / 4, -SECTION_SIZE / 4);

	// UIの生成
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
	// 作業UIの表示
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

	// メルトダウンカウントを減少させる
	_meltdownCount--;
	if (_meltdownCount > 0) return;

	// メルトダウンカウントが0になったら、エンティティーを暴走させる
	_pEntity->SetRunawayCount(0);
	_pEntity->RunawayEvent();
}

int SecureRoom::OperationProc()
{
	// 作業の進行、作業が終了してないなら返す
	if (!_pOperationList[(int)_selectOperation]->OperationProc()) return -1;
	// 作業が終了したら作業の結果を取得
	int successCount = _pOperationList[(int)_selectOperation]->GetSuccessCount();
	// エンティティの作業終了イベントを発生させる
	_pEntity->EndOperationEvent(successCount);
	// ステートを変更
	_currentState = State::IDLE;
	_pInteractOfficer = nullptr;

	return successCount;
}

void SecureRoom::StartOperation()
{
	// 待機状態でないなら返す
	if (_currentState != State::IDLE) return;

	_currentState = State::INTERACT;
	_pOperationList[(int)_selectOperation]->SetOperator(_pInteractOfficer);
	_pEntity->SetOperation(_selectOperation);
	// 作業開始イベントを発生させる
	_pEntity->StartOperationEvent();
}