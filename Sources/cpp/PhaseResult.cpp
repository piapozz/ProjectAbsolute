#include "../header/PhaseResult.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreenText.h"
#include "../header/UIScreenButton.h"
#include "../header/InputManager.h"
#include "../header/DataManager.h"
#include "../header/Camera.h"

void PhaseResult::Init()
{
	// 入力受付クラスを生成
	// 入力の初期化
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

	Transform trans = Transform(TEXT_POS, TEXT_SIZE);

	LayerSetting layer = {false, false, Layer::MIDDLE};
	UIScreenText* uiMessage = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(TEXT_POS, TEXT_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	uiMessage->SetText("ノルマ達成");
	uiMessage->SetFontSize(50);
	UIScreenText* uiMoney = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(MONEY_POS, MONEY_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	int money = DataManager::Instance().GetEnergy();
	std::string moneyText = "報酬 " + std::to_string(money);
	uiMoney->SetText(moneyText);
	uiMoney->SetFontSize(50);

	trans = Transform(RESTART_POS, RESTART_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* restartButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	restartButton->SetText("←");
	restartButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::STANDBY);
	});
	trans = Transform(NEXT_POS, NEXT_SIZE);
	UIScreenButton* nextButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	nextButton->SetText("NEXT");
	nextButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::SELECT);
		DataManager::Instance().AddMoney(DataManager::Instance().GetEnergy());
	});

	// カメラ生成
	_pCamera = new Camera();
}

void PhaseResult::OnCursorProc(Vector2 pos)
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
}

void PhaseResult::LPushInputProc(Vector2 pos)
{

}

void PhaseResult::RPushInputProc(Vector2 pos)
{

}

void PhaseResult::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseResult::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
}

void PhaseResult::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
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

void PhaseResult::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void PhaseResult::WheelRotInputProc(Vector2 pos, int rot)
{

}

void PhaseResult::EscapeInputProc()
{

}