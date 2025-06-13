#include "../header/SectionRoom.h"
#include "../header/Const.h"

void SectionRoom::Init(Transform setTransform, LayerSetting layerSetting)
{
	// 初期化
	BaseSection::Init(setTransform, layerSetting);
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