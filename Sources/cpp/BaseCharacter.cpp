#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacterState.h"
#include "../header/CharacterStateFactory.h"
#include "../header/StageManager.h"

void BaseCharacter::Init(LayerSetting layerSetting)
{
	objectType = ObjectType::CHARACTER;
	active = layerSetting.m_active;
	interactable = layerSetting.m_interact;
	layer =layerSetting.m_layer;
	transform.scale = Vector2(50, 50);

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
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
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

void BaseCharacter::ChangeMoveState(BaseSection* targetSection, CharacterStateID nextStateID)
{
	std::vector<Vector2> routeList;
	Vector2 targetPos = targetSection->GetPosition();
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 startPos = ObjectManager::Instance().FindPosObject(position, ObjectType::SECTION)->GetPosition();

	routeList = StageManager::FindPath(startPos, targetPos);
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;

	SecureRoom* secureRoom = dynamic_cast<SecureRoom*>(targetSection);

	if (secureRoom != nullptr)
	{
		args->secureRoom = secureRoom;
		ChangeState(CharacterStateID::OPERATION_MOVE, args);
		return;
	}
	args->stateID = nextStateID;
	ChangeState(CharacterStateID::MOVE, args);
}

void BaseCharacter::ChangeMoveState(Vector2 targetPosition, CharacterStateID nextStateID)
{
	std::vector<Vector2> routeList;
	Vector2 nowPositon = GetPosition();
	routeList.push_back(nowPositon);
	routeList.push_back(targetPosition);

	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	args->stateID = nextStateID;
	ChangeState(CharacterStateID::MOVE, args);
}
