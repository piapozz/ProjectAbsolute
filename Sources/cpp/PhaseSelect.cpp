#include "../header/PhaseSelect.h"
#include "../header/InputManager.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"
#include "../header/EntityManager.h"

void PhaseSelect::Init()
{
	// 入力を初期化
	InputManager& inputManager = InputManager::Instance();
	inputManager.SetOnCursorCallback([this](Vector2 pos) { this->OnCursorProc(pos); });
	inputManager.SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos) { this->LReleaseInputProc(pos, oldPos); });

	AudioManager::Instance().PlayBGM(BGM::OTHER);

	// 選択肢を初期化
	for (int i = 0; i < _MAX_SELECT_ENTITY; i++)
	{
		// エンティティーのプールから所持していないエンティティーを抜き出す
		// ランダムなエンティティーを追加する
		_selectEntityIDList[i] = 0;
	}

	// リストに応じたUIを生成
	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one());
	LayerSetting layer = LayerSetting(true, true, Layer::MIDDLE);
	Vector2 windowSize = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);

	for (int i = 0; i <_MAX_SELECT_ENTITY; i++)
	{
		worldTransform = Transform(windowSize / 2 + _SELECT_ENTITY_POS[i] * windowSize / 2, _SELECT_ENTITY_SCALE * windowSize);
		UIScreenButton* button = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
		button->SetCallback([this, i]() {
			// エンティティーを選択する
			this->SelectEntity(_selectEntityIDList[i]);
		});
		button->SetText("Entity_E000");
	}
}

void PhaseSelect::OnCursorProc(Vector2 pos)
{
	// 以前乗っていたオブジェクトを乗っていなくする
	BaseObject* onCursorObj = InputManager::Instance().GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// スクリーンUI
	// UIの取得
	BaseObject* screenUI = ObjectManager::Instance().FindPosObject(pos);
	if (screenUI != nullptr)
	{
		screenUI->OnCursor();
		InputManager::Instance().SetOnCursorObject(screenUI);
		return;
	}
	InputManager::Instance().SetOnCursorObject(nullptr);
}

void PhaseSelect::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// クリックが離されたなら
	if (InputManager::Instance().IsLeftClick(pos))
	{
		// スクリーンUI
		BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
		if (object != nullptr)
		{
			object->ClickEvent();
			return;
		}
	}
}

void PhaseSelect::SelectEntity(int selectNum)
{
	EntityManager::Instance().AddEntity(selectNum);
	ChangePhase(PhaseName::STANDBY);
}