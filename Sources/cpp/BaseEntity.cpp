#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	// マスターデータからID参照でパラメーターを取得
	_hazardLevel = 0;
	_maxRunawayCount = 3;
	_runawayCount = _maxRunawayCount;
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
	_runawayCount--;
	// 暴走カウンターが0になったら、暴走イベントを発生させる
	if (_runawayCount > 0) return;
	RunawayEvent();
}