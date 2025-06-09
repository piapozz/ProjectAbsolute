#include "../header/UIScreenButton.h"
#include "../header/Camera.h"
#include "../header/ObjectFactory.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting)
{
	// ������
	BaseUIScreen::Init(setPosition, setSize, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(setPosition, setSize, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(setPosition, setSize, fill, setLayer);
}

void UIScreenButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UIScreenButton::Draw()
{
	BaseUIScreen::Draw();
}

void UIScreenButton::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}