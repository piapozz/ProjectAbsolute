#include "../header/BaseCharacter.h"

void BaseCharacter::Init()
{
	objectType = ObjectType::CHARACTER;
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