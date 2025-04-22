#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

void BaseCharacter::Init()
{
	objectType = ObjectType::CHARACTER;
	objectSize = Vector2(50, 50);
	ObjectManager::AddObject(this);
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