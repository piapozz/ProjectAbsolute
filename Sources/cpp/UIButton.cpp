#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Transform setTransform, LayerSetting layerSetting)
{
	// 初期化
	BaseUI::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(setTransform, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(setTransform, setLayer);
}

void UIButton::Proc()
{
	// アップデート
	BaseUI::Proc();
	Vector2 position = transform.GetWorldPosition();
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