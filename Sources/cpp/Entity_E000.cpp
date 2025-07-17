#include "../header/Entity_E000.h"
#include "../header/ControllerEntityTriangle.h"
#include "../header/SelectorNearOfficerInRoom.h"
#include "../header/AttackSingle.h"
#include "../header/StageManager.h"

void Entity_E000::Init(LayerSetting layerSetting)
{
	BaseEgoEntity::Init(layerSetting);
	_groupType = CharacterGroup::ENTITY;
	pController = new ControllerEntityTriangle(this);

	AttackAction* normalAttack = new AttackAction();
	normalAttack->targetSelector = new SelectorNearOfficerInRoom();
	normalAttack->characterAttack = new AttackSingle();
	normalAttack->attackRange = 25;
	attackActions.push_back(normalAttack);

	for (int i = 0;i < (int)Type::MAX;i++)
	{
		defenseRatio[i] = 1.0f;
	}

	_attackStatus.attack = 10;
	_attackStatus.damageType = Type::WHITE;

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
	if (currentOperationType != Type::PALE) return;

	// 暴走カウンターを減らす
	DecreaseRunawayCount();
}

void Entity_E000::RunawayEvent()
{
	pController->isFreeze = false;

	StageManager& stageManager = StageManager::Instance();
	BaseSection* randomSection = stageManager.GetRandomSection();

	ChangeMoveState(randomSection);
}

void Entity_E000::Respawn()
{
	ChangeState(CharacterStateID::IDLE);
	targetCharacter = nullptr;
	pController->isFreeze = true;
	SetHealth(maxHealth);
	SetIsDead(false);
}