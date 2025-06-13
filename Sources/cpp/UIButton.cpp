#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Transform setTransform, LayerSetting layerSetting)
{
	// ������
	BaseUI::Init(setTransform, layerSetting);
	LayerSetting setLayer = layerSetting;
	setLayer.m_interact = false;
	_pText = ObjectFactory::Instance().CreateWithArgs<UIText>(setTransform, setLayer);
	setLayer.m_layer = Layer::BACK;
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIImage>(setTransform, setLayer);
}

void UIButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
	Vector2 position = transform.GetWorldPosition();
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