#include "../header/SelectOperationUI.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"

SelectOperationUI::SelectOperationUI()
{
	BaseUIScreen::Init(_TRANSFORM, _DEFAULT_LAYER);

	std::vector<Vector2> operationUIOffsetList((int)Type::MAX);
	operationUIOffsetList[0] = Vector2(-_OPERATION_SCALE, -_OPERATION_SCALE);
	operationUIOffsetList[1] = Vector2(_OPERATION_SCALE, -_OPERATION_SCALE);
	operationUIOffsetList[2] = Vector2(-_OPERATION_SCALE, _OPERATION_SCALE);
	operationUIOffsetList[3] = Vector2(_OPERATION_SCALE, _OPERATION_SCALE);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layerSetting = {false, true, Layer::MIDDLE};
	// UIÇÃê∂ê¨
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		Transform transform = Transform(operationUIOffsetList[i], Vector2(_OPERATION_SCALE, _OPERATION_SCALE), this);
		UIScreenButton* button = factory.CreateWithArgs<UIScreenButton>(transform, true, layerSetting);
		_pOperationUIList.push_back(button);
	}
}

void SelectOperationUI::Draw()
{
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pOperationUIList[i]->Draw();
	}
}

void SelectOperationUI::SetActive(bool active)
{
	BaseUIScreen::SetActive(active);
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_pOperationUIList[i]->SetActive(active);
	}
}