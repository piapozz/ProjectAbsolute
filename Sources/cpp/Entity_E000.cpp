#include "../header/Entity_E000.h"
#include "../header/ControllerEntityTriangle.h"
#include "../header/SelectorNearOfficerInRoom.h"
#include "../header/AttackSingle.h"

void Entity_E000::Init(LayerSetting layerSetting)
{
	BaseEgoEntity::Init(layerSetting);
	pController = new ControllerEntityTriangle(this);

	AttackAction* normalAttack = new AttackAction();
	normalAttack->targetSelector = new SelectorNearOfficerInRoom();
	normalAttack->characterAttack = new AttackSingle();
	normalAttack->attackRange = 500;

	attackActions.push_back(normalAttack);

	Transform trans = Transform(Vector2::zero(), Vector2::one(), this);
}

void Entity_E000::Proc()
{
	BaseEgoEntity::Proc();
	pCharacterState->Update(this);
 	pController->UpdateAI();
}

void Entity_E000::EndOperationEvent(int successCount)
{
	// 青作業なら処理
	if (_currentOperationType != Type::PALE) return;

	// 暴走カウンターを減らす
	DecreaseRunawayCount();
}