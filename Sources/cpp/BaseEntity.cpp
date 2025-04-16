#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	// マスターデータからID参照でパラメーターを取得
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Proc()
{
	
}

void BaseEntity::Draw()
{
	
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