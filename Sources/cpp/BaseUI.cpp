#include "../header/BaseUI.h"
#include "../header/ObjectManager.h"
#include "../header/Camera.h"

void BaseUI::Init(Transform setTransform, LayerSetting layerSetting)
{
	transform = setTransform;
	objectType = ObjectType::UI;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
}

void BaseUI::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();
}

void BaseUI::Draw()
{
	// �`��
	BaseObject::Draw();
}

void BaseUI::Teardown()
{
	// �j��
	BaseObject::Teardown();
}
