#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacterState.h"
#include "../header/CharacterStateFactory.h"
#include "../header/StageManager.h"

void BaseCharacter::Init()
{
	objectType = ObjectType::CHARACTER;
	layer = Layer::OBJECT;
	objectSize = Vector2(50, 50);

}

void BaseCharacter::Proc()
{
	// アップデート
	BaseObject::Proc();
}

void BaseCharacter::Draw()
{
	// 描画
	BaseObject::Draw();
	DrawGraph(drawHandle, position.x, position.y, TRUE);
}

void BaseCharacter::Teardown()
{
	// 破棄
	BaseObject::Teardown();
} 

void BaseCharacter::DecreaseHealth(int decreaseValue)
{
	health -= decreaseValue;
}

void BaseCharacter::ChangeState(CharacterStateID stateID, StateArgs* args)
{
	if (pCharacterState)
	{
		pCharacterState->Exit(this);
		delete pCharacterState;
	}

	pCharacterState = CharacterStateFactory::CreateState(stateID, args);

	if (pCharacterState)
	{
		pCharacterState->Enter(this);
	}
}

void BaseCharacter::ChangeMoveState(Vector2 targetPos, SecureRoom* secureRoom)
{
	std::vector<Vector2> routeList;
	routeList = StageManager::FindPath(position, targetPos);
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	if (secureRoom != nullptr)
	{
		args->secureRoom = secureRoom;
		ChangeState(CharacterStateID::OPERATION_MOVE, args);
		_pastPosition = routeList[0];
		return;
	}
	ChangeState(CharacterStateID::MOVE, args);
	// 過去の位置を保存
	_pastPosition = routeList[0];
}

//bool BaseCharacter::CharacterMove(std::vector<Vector2> targetPosList, float speed)
//{
//	Vector2 current = GetPosition();
//	Vector2 target = targetPosList[_moveListIndex];
//
//	// x方向の移動
//	float dx = target.x - current.x;
//	float distance = std::abs(dx);
//
//	float moveX = (dx / distance) * speed;
//	current.x += moveX;
//	current.y = target.y;
//
//	SetPosition(current);
//
//	// 目的地に到着したら次の目的地へ移動
//	if (distance < 2.0f)
//	{
//		current.x = target.x;
//		SetPosition(current);
//		_moveListIndex++;
//	}
//
//	// すべてのルートに到達したらステート遷移
//	if (_moveListIndex == targetPosList.size())
//	{
//		_moveListIndex = 0;
//		return true;
//	}
//
//	return false;
//}