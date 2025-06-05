#include "../header/BaseEgoEntity.h"

void BaseEgoEntity::Init(LayerSetting layerSetting)
{
	BaseEntity::Init(layerSetting);
	isRunaway = false;
}

void BaseEgoEntity::Proc()
{
	BaseEntity::Proc();

	// 行動の決定
	// 脱走してないなら返す
	if (!isRunaway) return;
	// 同室に攻撃対象がいるか確認
	// いるならステートを攻撃に移行
	// いないならステートを移動に変更

}
