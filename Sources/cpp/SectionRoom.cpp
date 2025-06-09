#include "../header/SectionRoom.h"
#include "../header/Const.h"

void SectionRoom::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// 初期化
	BaseSection::Init(setPosition, setSize, layerSetting);
}

void SectionRoom::Proc()
{
	// アップデート
	BaseSection::Proc();
}

void SectionRoom::Draw()
{
   // 描画
   BaseSection::Draw();
}

void SectionRoom::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}