#include "../header/BaseUIScreen.h"
#include "../header/ObjectManager.h"

void BaseUIScreen::Init(Transform setTransform, LayerSetting layerSetting)
{
	transform = setTransform;
	objectType = ObjectType::SCREEN_UI;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
}

void BaseUIScreen::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();
}

void BaseUIScreen::Draw()
{
	// �`��
	BaseObject::Draw();
}

void BaseUIScreen::Teardown()
{
	// �j��
	BaseObject::Teardown();
}