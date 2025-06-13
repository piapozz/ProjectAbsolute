#include "../header/UIScreenSlider.h"
#include "../header/ObjectFactory.h"

void UIScreenSlider::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
}

void UIScreenSlider::Proc()
{
	// アップデート
	BaseUIScreen::Proc();

	_pImage->Proc();
	_pText->Proc();
}

void UIScreenSlider::Draw()
{
	_pImage->Draw();
	// 四角を描画
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	int x1 = position.x - scale.x / 2;
	int y1 = position.y - scale.y / 2;
	int x2 = x1 + (scale.x * _value);
	int y2 = position.y + scale.y / 2;

	DrawBoxAA(x1, y1, x2, y2, _color, TRUE);
	BaseUIScreen::Draw();
	_pText->Draw();
}

void UIScreenSlider::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}