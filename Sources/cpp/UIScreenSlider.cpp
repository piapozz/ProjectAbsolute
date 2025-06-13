#include "../header/UIScreenSlider.h"
#include "../header/ObjectFactory.h"

void UIScreenSlider::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(setTransform, fill, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(setTransform, setLayer);
}

void UIScreenSlider::Proc()
{
	// アップデート
	BaseUIScreen::Proc();
	Vector2 position = transform.GetWorldPosition();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UIScreenSlider::Draw()
{
	// 四角を描画
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	int x1 = position.x - scale.x / 2;
	int y1 = position.y - scale.y / 2;
	int x2 = x1 + (scale.x * _value);
	int y2 = position.y + scale.y / 2;

	DrawBoxAA(x1, y1, x2, y2, _color, TRUE);

	BaseUIScreen::Draw();
}

void UIScreenSlider::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}