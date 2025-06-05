#include "../header/SectionCorridor.h"

#include "../header/Const.h"

void SectionCorridor::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	// 初期化
	BaseSection::Init(setPosition, setSize, layerSetting);
}

void SectionCorridor::Proc()
{
	// アップデート
	BaseSection::Proc();
}

void SectionCorridor::Draw()
{
	// 描画
	BaseSection::Draw();
}

void SectionCorridor::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}