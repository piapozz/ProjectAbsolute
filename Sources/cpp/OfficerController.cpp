#include "../header/OfficerController.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacter.h"
#include "../header/SecureRoom.h"

void OfficerController::UpdateAI() 
{
	DecideState();
}

void OfficerController::DecideState() 
{
	CharacterController::DecideState();

	if (officer->GetMental() <= 0)
	{
		character->ChangeState(CharacterStateID::PANIC);
		return;
	}

	switch (character->stateID)
	{
		case CharacterStateID::IDLE:
			UpdateIdleState();
			break;

		case CharacterStateID::MOVE:
			UpdateMoveState();
			break;

		case CharacterStateID::FIGHT:
			UpdateMoveState();
			break;
	}

	return;
}

void OfficerController::UpdateIdleState()
{
	if (!WaitUntilCount()) return;

	Vector2 nextPosition = GetRandomPositionInRoom();

	// 部屋内で適当に移動
	character->ChangeMoveState(nextPosition);
}

void OfficerController::UpdateMoveState() 
{
	BaseCharacterState* state = character->pCharacterState;

	BaseCharacterState* characterState = character->pCharacterState;

	// 自身の状態を確認してステートを分岐
	if (!characterState->IsEndState()) return;

	// もしターゲットを持っていたら
	//if (officer->targetCharacter)
	//{
	//	officer->ChangeState(CharacterStateID::FIGHT);
	//	return;
	//}

	// SecureRoom かどうかをチェック
	BaseObject* sectionObject = ObjectManager::Instance().FindPosObject(character->GetPosition(), ObjectType::SECTION);
	SecureRoom* secureRoom = dynamic_cast<SecureRoom*>(sectionObject);

	if (secureRoom)
	{
		character->ChangeState(CharacterStateID::OPERATION);
		return;
	}

	character->ChangeState(CharacterStateID::IDLE);
	return;
}

void OfficerController::UpdateFightState()
{

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

bool OfficerController::CheckHostility()
{

}