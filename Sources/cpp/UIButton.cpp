#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// 初期化
	BaseUI::Init(setPosition, setSize, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(setPosition, setSize, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(setPosition, setSize, setLayer);
}

void UIButton::Proc()
{
	// アップデート
	BaseUI::Proc();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UIButton::Draw()
{
	// 描画
	BaseUI::Draw();
}

void UIButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}