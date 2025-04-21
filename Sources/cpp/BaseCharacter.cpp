#include "../header/BaseCharacter.h"

void BaseCharacter::Init()
{
	objectType = ObjectType::CHARACTER;
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