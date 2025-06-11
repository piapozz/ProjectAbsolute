#include "../header/OfficerController.h"
#include "../header/BaseCharacter.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"
#include "../header/ObjectManager.h"

void OfficerController::UpdateAI()
{
	DecideState();
}

void OfficerController::DecideState()
{
	CharacterStateID stateID = officer->stateID;

	switch (stateID)
	{
		case CharacterStateID::IDLE:
			UpdateIdleState();
			break;

		case CharacterStateID::MOVE:
			UpdateMoveState();
			break;

		default:
			// 他ステート処理（今後拡張）
			break;
	}
}

void UpdateIdleState()
{
	if (!HasWaitedEnough()) return;

	//Vector2 nextPosition = GetRandomPositionInCurrentSection();

	// 部屋内で適当に移動
	//character->ChangeMoveState(nextPosition, CharacterStateID::IDLE);
}

bool HasWaitedEnough()
{
	int nowCount = GetNowCount();
	//int elapsed = nowCount - startCount;

	//if (elapsed >= _waitCount)
	//{
	//	startCount = nowCount; 
	//	return true;
	//}
	return false;
}

Vector2 GetRandomPositionInRoom()
{
	//ObjectManager& objectManager = ObjectManager::Instance();
	//Vector2 characterPosition = character->GetPosition();

	//BaseObject* sectionObject = objectManager.FindPosObject(characterPosition, ObjectType::SECTION);
	//if (!sectionObject) return characterPosition;

	//Vector2 sectionPosition = sectionObject->GetPosition();
	//Vector2 sectionSize = sectionObject->GetSize();

	//int left = sectionPosition.x - sectionSize.x / 2;
	//int right = sectionPosition.x + sectionSize.x / 2;
	//float randValue = GetRand(right - left) + left;

	//return {randValue, characterPosition.y};
}

void UpdateMoveState()
{
	//BaseCharacterState* characterState = officer->pCharacterState;
	//if (!characterState->EndState()) return;

	//// SecureRoom かどうかをチェック
	//BaseObject* sectionObject = ObjectManager::Instance().FindPosObject(character->GetPosition(), ObjectType::SECTION);
	//SecureRoom* secureRoom = dynamic_cast<SecureRoom*>(sectionObject);

	//if (secureRoom)
	//{
	//	character->ChangeState(CharacterStateID::OPERATION);
	//} else
	//{
	//	character->ChangeState(CharacterStateID::IDLE);
	//}
}