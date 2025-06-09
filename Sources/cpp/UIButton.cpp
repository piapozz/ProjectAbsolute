#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// ������
	BaseUI::Init(setPosition, setSize, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(setPosition, setSize, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(setPosition, setSize, setLayer);
}

void UIButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
	_pImage->SetPosition(position);
	_pText->SetPosition(position);
}

void UIButton::Draw()
{
	// �`��
	BaseUI::Draw();
}

void UIButton::Teardown()
{
	// �j��
	BaseUI::Teardown();
}