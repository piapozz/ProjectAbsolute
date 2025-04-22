#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	BaseCharacter::Init();
	// マスターデータからID参照でパラメーターを取得
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Draw()
{
	DrawSphere3D(VGet(position.x, position.y, 0), 10, 32, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}

void BaseEntity::Teardown()
{
	
}

void BaseEntity::DecreaseRunawayCount()
{
	// 暴走カウンターを減少させる
	runawayCount--;
	// 暴走カウンターが0になったら、暴走イベントを発生させる
	if (runawayCount > 0) return;
	RunawayEvent();
}