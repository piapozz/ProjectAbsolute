#include "../header/SectionConnect.h"

#include "../header/Const.h"

void SectionConnect::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// 初期化
	BaseSection::Init(setPosition, setSize, layerSetting);
	layer = layerSetting.m_layer;
}

void SectionConnect::Proc()
{
	// アップデート
	BaseSection::Proc();
}

void SectionConnect::Draw()
{
	// 描画
	BaseSection::Draw();
}

void SectionConnect::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}