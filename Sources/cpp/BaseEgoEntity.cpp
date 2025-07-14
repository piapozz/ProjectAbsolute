#include "../header/BaseEgoEntity.h"
#include "../header/ObjectFactory.h"

void BaseEgoEntity::Init(LayerSetting layerSetting)
{
	BaseEntity::Init(layerSetting);
	isRunaway = false;
	Transform trans = Transform(Vector2::zero(), Vector2::one(), this);
	LayerSetting setting = { false, false , Layer::MIDDLE};
	text = ObjectFactory::Instance().CreateWithArgs<UIText>(trans, setting);

	health = 100;
	maxHealth = health;
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

	text->SetActive(true);
	text->SetText("暴走");
}

void BaseEgoEntity::Draw()
{
	BaseEntity::Draw();
	if(text->GetActive()) text->Draw();
}
