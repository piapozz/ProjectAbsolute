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
	objectSize = Vector2(50, 50);

}

void BaseCharacter::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();
}

void BaseCharacter::Draw()
{
	// �`��
	BaseObject::Draw();
	DrawGraph(drawHandle, position.x, position.y, TRUE);
}

void BaseCharacter::Teardown()
{
	// �j��
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

//bool BaseCharacter::CharacterMove(std::vector<Vector2> targetPosList, float speed)
//{
//	Vector2 current = GetPosition();
//	Vector2 target = targetPosList[_moveListIndex];
//
//	// x�����̈ړ�
//	float dx = target.x - current.x;
//	float distance = std::abs(dx);
//
//	float moveX = (dx / distance) * speed;
//	current.x += moveX;
//	current.y = target.y;
//
//	SetPosition(current);
//
//	// �ړI�n�ɓ��������玟�̖ړI�n�ֈړ�
//	if (distance < 2.0f)
//	{
//		current.x = target.x;
//		SetPosition(current);
//		_moveListIndex++;
//	}
//
//	// ���ׂẴ��[�g�ɓ��B������X�e�[�g�J��
//	if (_moveListIndex == targetPosList.size())
//	{
//		_moveListIndex = 0;
//		return true;
//	}
//
//	return false;
//}