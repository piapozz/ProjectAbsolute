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
	// アップデート
	BaseObject::Proc();
}

void BaseUI::Draw()
{
	// 描画
	BaseObject::Draw();
}

void BaseUI::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}
