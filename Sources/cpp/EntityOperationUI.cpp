#include "../header/EntityOperationUI.h"
#include "../header/EntityOperationSummaryUI.h"
#include "../header/ObjectFactory.h"

EntityOperationUI::EntityOperationUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	/*for (int i = 0; i < (int)Type::MAX; i++)
	{
		EntityOperationSummaryUI* summary = factory.CreateWithArgs<EntityOperationSummaryUI>(worldTransform, layer);
		_summaryUIList.push_back(summary);
	}*/

	// ˜g
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_informationBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	_information = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_information->SetText(_INFORMATION_TEXT);
}

void EntityOperationUI::Draw()
{
	_informationBGImage->Draw();
	_information->Draw();
}