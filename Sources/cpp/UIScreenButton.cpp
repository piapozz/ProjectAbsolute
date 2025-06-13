#include "../header/UIScreenButton.h"
#include "../header/Camera.h"
#include "../header/ObjectFactory.h"

void UIScreenButton::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// 初期化
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	Transform trans = Transform();
	trans.parent = this;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(trans, setLayer);
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(trans, fill, setLayer);
}

void UIScreenButton::Proc()
{
	// アップデート
	BaseUIScreen::Proc();

	_pImage->Proc();
	_pText->Proc();
}

void UIScreenButton::Draw()
{
	BaseUIScreen::Draw();

	_pImage->Draw();
	_pText->Draw();
}

void UIScreenButton::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}