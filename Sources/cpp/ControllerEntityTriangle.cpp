#include "../header/ControllerEntityTriangle.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/SecureRoom.h"
#include "../header/SelectorNearEntityInRoom.h"

void ControllerEntityTriangle::UpdateAI()
{
	if(!isFreeze) DecideState();
}

void ControllerEntityTriangle::DecideState()
{
	BaseController::DecideState();
	CharacterStateID stateID = character->stateID;

	if (character->GetIsDead()) return;

	if (character->GetHealth() <= 0)
	{
		character->SetIsDead(true);
		character->ChangeState(CharacterStateID::DEAD);
		return;
	}

	switch (stateID)
	{
		case CharacterStateID::IDLE:
			UpdateIdleState();
			break;

		case CharacterStateID::MOVE:
			UpdateMoveState();
			break;

		case CharacterStateID::FIGHT:
			UpdateFightState();
			break;
		case CharacterStateID::DEAD:
			UpdateDeadState();
			break;
	}

	return;
}

void ControllerEntityTriangle::UpdateIdleState()
{
	BaseCharacter* checkTarget = CheckHostility();
	if (checkTarget)
	{
		character->SetTargetCharacter(checkTarget);
		character->ChangeState(CharacterStateID::FIGHT);
		return;
	}

	if (!WaitUntilCount()) return;

	Vector2 nextPosition = GetRandomPositionInRoom();
	character->ChangeMoveState(nextPosition);
}

void ControllerEntityTriangle::UpdateMoveState()
{
	BaseCharacter* targetCharacter = character->targetCharacter;
	if (character->GetIsFight() && targetCharacter != nullptr)
	{
		Vector2 targetPos = targetCharacter->GetTransform().position;
		Vector2 attackerPos = character->GetTransform().position;
		int dx = targetPos.x - attackerPos.x;
		int dy = targetPos.y - attackerPos.y;
		int attackRange = character->attackActions[0]->attackRange;
		int verticalRange = 50;

		if (abs(dx) <= attackRange && abs(dy) <= verticalRange)
		{
			character->ChangeState(CharacterStateID::FIGHT);
			return;
		}
	}

	if (!character->pCharacterState->IsEndState()) return;

	if (character->GetIsFight())
	{
		character->ChangeState(CharacterStateID::FIGHT);
		return;
	}

	character->ChangeState(CharacterStateID::IDLE);
}

void ControllerEntityTriangle::UpdateFightState()
{
	BaseCharacter* targetCharacter = character->targetCharacter;

	// ターゲットがいなかったら待機に戻る
	if (!targetCharacter || targetCharacter->GetIsDead())
	{
		BaseCharacter* newTarget = CheckHostility();
		if (newTarget)
		{
			character->SetTargetCharacter(newTarget);
			return;
		}

		character->ClearTargetCharacter();
		character->ChangeState(CharacterStateID::IDLE);
		return;
	}

	// 同じ部屋にいなかったら追いかける
	ObjectManager& objectManager = ObjectManager::Instance();
	BaseObject* mySection = objectManager.FindPosObject(character->GetPosition(), ObjectType::SECTION);
	BaseObject* targetSection = objectManager.FindPosObject(targetCharacter->GetPosition(), ObjectType::SECTION);
	if (mySection != targetSection)
	{
		BaseSection* section = static_cast<BaseSection*>(targetSection);
		character->ChangeMoveState(section);
		return;
	}

	// 移動中に射程内に入ったら攻撃
	Vector2 targetPos = targetCharacter->GetTransform().position;
	Vector2 attackerPos = character->GetTransform().position;
	int attackRange = character->attackActions[0]->attackRange;
	int dx = targetPos.x - attackerPos.x;
	int dy = targetPos.y - attackerPos.y;
	int verticalRange = 50;
	if (abs(dx) > attackRange || abs(dy) > verticalRange)
	{
		character->ChangeMoveState(targetPos, CharacterStateID::FIGHT);
		return;
	}
	return;
}

void ControllerEntityTriangle::UpdateDeadState()
{
	
}

bool ControllerEntityTriangle::WaitUntilCount()
{
	int nowCount = GetNowCount();
	int elapsed = nowCount - _startCount;

	if (elapsed >= _waitCount)
	{
		_startCount = nowCount;
		return true;
	}
	return false;
}

Vector2 ControllerEntityTriangle::GetRandomPositionInRoom()
{
	Transform characterTransform = character->GetTransform();
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 characterPosition = characterTransform.position;

	BaseObject* sectionObject = objectManager.FindPosObject(characterPosition, ObjectType::SECTION);
	if (!sectionObject) return characterPosition;

	Vector2 sectionPosition = sectionObject->GetTransform().position;
	Vector2 sectionSize = sectionObject->GetTransform().scale;

	float characterHalfWidth = characterTransform.scale.x / 2.0f;

	float sectionLeft = sectionPosition.x - sectionSize.x / 2.0f;
	float sectionRight = sectionPosition.x + sectionSize.x / 2.0f;

	float left = sectionLeft + characterHalfWidth;
	float right = sectionRight - characterHalfWidth;

	if (right <= left) return characterPosition;

	float randValue = left + static_cast<float>(GetRand(static_cast<int>(right - left + 1)));

	return {randValue, characterPosition.y};
}

BaseCharacter* ControllerEntityTriangle::CheckHostility()
{
	ITargetSelector* selector = character->GetAttackAction()[0]->targetSelector;
	std::vector<BaseCharacter*> targetList = selector->SelectTargets(character);
	if (targetList.empty()) return nullptr;

	return targetList[0];
}

