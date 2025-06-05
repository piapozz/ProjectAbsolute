#include "../header/UIManager.h"
#include "../header/UIScreenButton.h"
#include "../header/ObjectFactory.h"

std::vector<UIScreenButton*> UIManager::_pOperationUIList;

UIManager::UIManager()
{
	// オフセットを初期化
	Vector2 uiCenter = Vector2(0, WINDOW_HEIGHT) + Vector2(_SCREEN_UI_SIZE_X / 2, -_SCREEN_UI_SIZE_Y / 2);
	std::vector<Vector2> operationUIOffsetList((int)Type::MAX);
	operationUIOffsetList[0] = Vector2(-_SCREEN_UI_SIZE_X / 4, -_SCREEN_UI_SIZE_Y / 4);
	operationUIOffsetList[1] = Vector2(_SCREEN_UI_SIZE_X / 4, -_SCREEN_UI_SIZE_Y / 4);
	operationUIOffsetList[2] = Vector2(-_SCREEN_UI_SIZE_X / 4, _SCREEN_UI_SIZE_Y / 4);
	operationUIOffsetList[3] = Vector2(_SCREEN_UI_SIZE_X / 4, _SCREEN_UI_SIZE_Y / 4);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layerSetting = {true, true, Layer::MIDDLE};
	// UIの生成
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		UIScreenButton* button = factory.CreateWithArgs<UIScreenButton>(uiCenter + operationUIOffsetList[i], Vector2(_SCREEN_UI_SIZE_X / 2, _SCREEN_UI_SIZE_Y / 2), true, layerSetting);
		button->SetActive(false);
		_pOperationUIList.push_back(button);
	}
}
std::vector<UIScreenButton*> UIManager::GetOperationUIList()
{
	return _pOperationUIList;
}

void UIManager::SetActiveOperationUI(bool active)
{
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pOperationUIList[i]->SetActive(active);
	}
}