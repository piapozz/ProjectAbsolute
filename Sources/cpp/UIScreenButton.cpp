#include "../header/UIScreenButton.h"
#include "../header/Camera.h"
#include "../header/ObjectFactory.h"

void UIScreenButton::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	// ������
	BaseUIScreen::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(setTransform, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(setTransform, fill, setLayer);
}

void UIScreenButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
	Vector2 position = transform.GetWorldPosition();
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