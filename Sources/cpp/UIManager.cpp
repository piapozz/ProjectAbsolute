#include "../header/ObjectFactory.h"
#include "../header/UIManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIEntity.h"
#include "../header/UIOfficer.h"

UIManager::UIManager()
{
	for (int i = 0; i < FONT_SIZE_MAX; i++)
	{
		_fontHandle[i] = CreateFontToHandle("ＭＳ ゴシック", i, 1);
	}

	// オフセットを初期化
	Vector2 uiCenter = Vector2(0, WINDOW_HEIGHT) + Vector2(_OPERATION_SIZE_X / 2, -_OPERATION_SIZE_Y / 2);
	std::vector<Vector2> operationUIOffsetList((int)Type::MAX);
	operationUIOffsetList[0] = Vector2(-_OPERATION_SIZE_X / 4, -_OPERATION_SIZE_Y / 4);
	operationUIOffsetList[1] = Vector2(_OPERATION_SIZE_X / 4, -_OPERATION_SIZE_Y / 4);
	operationUIOffsetList[2] = Vector2(-_OPERATION_SIZE_X / 4, _OPERATION_SIZE_Y / 4);
	operationUIOffsetList[3] = Vector2(_OPERATION_SIZE_X / 4, _OPERATION_SIZE_Y / 4);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layerSetting = {true, true, Layer::MIDDLE};
	// UIの生成
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		Transform transform = Transform(uiCenter + operationUIOffsetList[i], Vector2(_OPERATION_SIZE_X / 2, _OPERATION_SIZE_Y / 2));
		UIScreenButton* button = factory.CreateWithArgs<UIScreenButton>(transform, true, layerSetting);
		button->SetActive(false);
		_pOperationUIList.push_back(button);
	}
	_pEntityUI = factory.CreateWithArgs<UIEntity>();
	layerSetting = {false, false, Layer::MIDDLE};
	Transform trans = Transform(Vector2(WINDOW_WIDTH - (WINDOW_WIDTH / 10), WINDOW_HEIGHT / 5), Vector2(WINDOW_WIDTH / 5, WINDOW_HEIGHT / 2.5f));
	_pOfficerUI = factory.CreateWithArgs<UIOfficer>(trans, true, layerSetting);
}

UIManager::~UIManager()
{
	for (int i = 0; i < FONT_SIZE_MAX; i++)
	{
		DeleteFontToHandle(_fontHandle[i]);
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

void UIManager::SetActiveEntityUI(bool active)
{
	_pEntityUI->SetActive(active);
}

void UIManager::SetActiveOfficerUI(bool active)
{
	_pOfficerUI->SetActive(active);
}

void UIManager::SetOfficerUI(BaseOfficer* setOfficer)
{
	_pOfficerUI->SetOfficer(*setOfficer);
	SetActiveOfficerUI(true);
}

int UIManager::GetFontHandle(int size)
{
	if (size < 0 || size > FONT_SIZE_MAX) return -1;

	return _fontHandle[size];
}