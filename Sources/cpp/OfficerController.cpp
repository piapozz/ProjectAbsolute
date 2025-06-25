#include "../header/OfficerController.h"
#include "../header/ObjectManager.h"
#include "../header/SecureRoom.h"
#include "../header/SelectorNearEntityInRoom.h"

void OfficerController::UpdateAI()
{
	DecideState();
}

void OfficerController::DecideState()
{
	BaseController::DecideState();
	CharacterStateID stateID = character->stateID;

	if (character->GetIsDead()) return;

	if (!character->GetIsDead())
	{
		if (character->GetHealth() <= 0)
		{
			character->SetIsDead(true);
			character->ChangeState(CharacterStateID::DEAD);
			return;
		}
	}

	if (stateID != CharacterStateID::PANIC && officer->GetMental() <= 0)
	{
		character->ChangeState(CharacterStateID::PANIC);
		return;
	}

	// もしターゲットを持っていたら
	if (stateID != CharacterStateID::FIGHT && officer->targetCharacter)
	{
		// クリックで移動が行われたらtargetをクリア
		officer->ChangeState(CharacterStateID::FIGHT);
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
	}

	return;
}

void OfficerController::UpdateIdleState()
{
	BaseCharacter* checkTarget = CheckHostility();
	if (checkTarget)
	{
		character->targetCharacter = checkTarget;
		character->ChangeState(CharacterStateID::FIGHT);
		return;
	}

	if (!WaitUntilCount()) return;

	Vector2 nextPosition = GetRandomPositionInRoom();

	// 部屋内で適当に移動
	character->ChangeMoveState(nextPosition);
}

void OfficerController::UpdateMoveState()
{
	BaseCharacterState* characterState = character->pCharacterState;

	// 自身の状態を確認してステートを分岐
	if (!characterState->IsEndState()) return;

	// SecureRoom かどうかをチェック
	BaseObject* sectionObject = ObjectManager::Instance().FindPosObject(character->GetPosition(), ObjectType::SECTION);
	SecureRoom* secureRoom = dynamic_cast<SecureRoom*>(sectionObject);

	if (secureRoom)
	{
		character->ChangeState(CharacterStateID::OPERATION);
		return;
	}

	if(character->targetCharacter) character->ChangeState(CharacterStateID::FIGHT);

	character->ChangeState(CharacterStateID::IDLE);
	return;
}

void OfficerController::UpdateFightState()
{
	BaseCharacter* targetCharacter = character->targetCharacter;

	if (!targetCharacter || targetCharacter->GetIsDead())
	{
		BaseCharacter* newTarget = CheckHostility();
		if (newTarget)
		{
			character->targetCharacter = newTarget;
			return;
		}

		character->targetCharacter = nullptr;
		character->ChangeState(CharacterStateID::IDLE);
		return;
	}

	ObjectManager& objectManager = ObjectManager::Instance();
	BaseObject* mySection = objectManager.FindPosObject(character->GetPosition(), ObjectType::SECTION);
	BaseObject* targetSection = objectManager.FindPosObject(targetCharacter->GetPosition(), ObjectType::SECTION);

	if (mySection != targetSection)
	{
		character->ChangeMoveState(targetCharacter->GetTransform().position);
		return;
	}

	Vector2 attackerPos = character->GetTransform().position;
	Vector2 targetPos = targetCharacter->GetTransform().position;
	int dx = targetPos.x - attackerPos.x;
	int attackRange = character->attackActions[0]->attackRange;

	if (abs(dx) > attackRange)
	{
		character->ChangeMoveState(targetCharacter->GetTransform().position);
		return;
	}

}

bool OfficerController::WaitUntilCount()
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

Vector2 OfficerController::GetRandomPositionInRoom()
{
	Transform characterTransform = character->GetTransform();

	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 characterPosition = characterTransform.position;

	BaseObject* sectionObject = objectManager.FindPosObject(characterPosition, ObjectType::SECTION);
	if (!sectionObject) return characterPosition;

	Vector2 sectionPosition = sectionObject->GetTransform().position;
	Vector2 sectionSize = sectionObject->GetTransform().scale;

	int left = sectionPosition.x - sectionSize.x / 2;
	int right = sectionPosition.x + sectionSize.x / 2;
	float randValue = GetRand(right - left) + left;

	return {randValue, characterPosition.y};
}

BaseCharacter* OfficerController::CheckHostility()
{
	ITargetSelector* selector = character->GetAttackAction()[0]->targetSelector;
	std::vector<BaseCharacter*> targetList = selector->SelectTargets(character);
	if (targetList.empty()) return nullptr;

	return targetList[0];
}