#include "../header/SceneTitle.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreenText.h"
#include "../header/UIScreenButton.h"
#include "../header/Camera.h"
#include "../header/AudioManager.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
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

	int i = AudioManager::Instance().GetVolume();
	AudioManager::Instance().PlayBGM(BGM::TITLE);

	Transform trans = Transform(TITLE_POS, TITLE_SIZE);

	LayerSetting layer = {true, false, Layer::MIDDLE};
	UIScreenText* uiTitle = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(TITLE_POS, TITLE_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	uiTitle->SetText("Absolute");
	uiTitle->SetFontSize(TITLE_FONT_SIZE);

	//trans = Transform(CONTINUE_POS, CONTINUE_SIZE);
	//layer = {true, true, Layer::BACK};
	//UIScreenButton* continueButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	//continueButton->SetText("Conitinue");

	trans = Transform(NEW_GAME_POS, NEW_GAME_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* newGameButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	newGameButton->SetText("New Game");
	newGameButton->SetCallback([this]() {
		if (ChangeScene != nullptr) ChangeScene(SceneName::MAIN);
	});

	trans = Transform(EXIT_POS, EXIT_SIZE);
	UIScreenButton* exitButtton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	exitButtton->SetText("Exit");
	exitButtton->SetCallback([this]() {
		if (ChangeScene != nullptr) ChangeScene(SceneName::EXIT);
	});
}

void SceneTitle::OnCursorProc(Vector2 pos)
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

void SceneTitle::LPushInputProc(Vector2 pos)
{

}

void SceneTitle::RPushInputProc(Vector2 pos)
{

}

void SceneTitle::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{

}

void SceneTitle::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
}

void SceneTitle::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
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

void SceneTitle::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void SceneTitle::WheelRotInputProc(Vector2 pos, int rot)
{

}

void SceneTitle::EscapeInputProc()
{

}
