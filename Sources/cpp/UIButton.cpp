#include "../header/UIButton.h"
#include "../header/ObjectFactory.h"

void UIButton::Init(Transform setTransform, LayerSetting layerSetting)
{
	// ������
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
	// �A�b�v�f�[�g
	BaseUI::Proc();

	_pImage->Proc();
	_pText->Proc();
}

void UIButton::Draw()
{
	// �`��
	BaseUI::Draw();
	_pImage->Draw();
	_pText->Draw();
}

void UIButton::Teardown()
{
	// �j��
	BaseUI::Teardown();
}