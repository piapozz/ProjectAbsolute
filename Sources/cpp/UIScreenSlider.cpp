#include "../header/UIScreenSlider.h"
#include "../header/ObjectFactory.h"

void UIScreenSlider::Init(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setPosition, setSize, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(setPosition, setSize, fill, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(setPosition, setSize, setLayer);
}

void UIScreenSlider::Proc()
{
	// アップデート
	BaseUIScreen::Proc();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UIScreenSlider::Draw()
{
	// 四角を描画
	int x1 = position.x - objectSize.x / 2;
	int y1 = position.y - objectSize.y / 2;
	int x2 = x1 + (objectSize.x * _value);
	int y2 = position.y + objectSize.y / 2;

	DrawBoxAA(x1, y1, x2, y2, _color, TRUE);

	BaseUIScreen::Draw();
}

void UIScreenSlider::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}