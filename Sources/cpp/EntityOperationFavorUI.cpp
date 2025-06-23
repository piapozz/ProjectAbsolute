#include "../header/EntityOperationFavorUI.h"
#include "../header/ObjectFactory.h"

EntityOperationFavorUI::EntityOperationFavorUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();

	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
}

void EntityOperationFavorUI::Draw()
{
	_BGImage->Draw();
}