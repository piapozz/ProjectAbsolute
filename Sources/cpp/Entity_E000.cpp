#include "../header/Entity_E000.h"

void Entity_E000::Init(LayerSetting layerSetting)
{
	BaseEgoEntity::Init(layerSetting);

	Transform trans = Transform(Vector2::zero(), Vector2::one(), this);
}

void Entity_E000::EndOperationEvent(int successCount)
{
	// 青作業なら処理
	if (_currentOperationType != Type::PALE) return;

	// 暴走カウンターを減らす
	DecreaseRunawayCount();
}