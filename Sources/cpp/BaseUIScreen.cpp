#include "../header/BaseUIScreen.h"
#include "../header/ObjectManager.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	_screenPos = setPosition;
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SCREEN_UI;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer = layerSetting.m_layer;
}

void BaseUIScreen::Proc()
{
	// アップデート
	BaseObject::Proc();
}

void BaseUIScreen::Draw()
{
	// 描画
	BaseObject::Draw();
}

void BaseUIScreen::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}