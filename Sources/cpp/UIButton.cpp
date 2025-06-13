#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Transform setTransform, LayerSetting layerSetting)
{
	// 初期化
	BaseUI::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(trans, setLayer);
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(trans, setLayer);
}

void UIButton::Proc()
{
	// アップデート
	BaseUI::Proc();

	_pImage->Proc();
	_pText->Proc();
}

void UIButton::Draw()
{
	// 描画
	BaseUI::Draw();
	_pImage->Draw();
	_pText->Draw();
}

void UIButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}