#include "../header/BaseCharacter.h"

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