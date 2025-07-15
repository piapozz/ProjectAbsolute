#include "../header/BaseEntity.h"
#include "../header/UIButton.h"
#include <cmath>

void BaseEntity::Init(LayerSetting layerSetting)
{
	BaseCharacter::Init(layerSetting);
	_groupType = CharacterGroup::ENTITY;
	// マスターデータからID参照でパラメーターを取得
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Proc()
{
	BaseCharacter::Proc();
}

void BaseEntity::Draw()
{
	//VECTOR pos[3];
	//for (int i = 0; i < 3; i++)
	//{
	//	float angle = 2.0f / 3.0f * DX_PI * i;
	//	Transform transformWorld = transform.GetWorldTransform();
	//	Vector2 position = transformWorld.position;
	//	pos[i] = VGet(position.x + cos(angle) * 30, position.y + sin(angle) * 30, 0);
	//}

	//DrawTriangle3D(pos[0], pos[1], pos[2], GetColor(255, 255, 255), false);

	BaseObject::Draw();

	int temp = 0 * 360 / 100;
	float radian = (float)temp * DX_PI / 180.0f;
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	float x = cosf(radian) * (scale.y / 2);
	float y = sinf(radian) * (scale.y / 2);
	VECTOR Pos1 = VGet(position.x + x, (position.y + (scale.y / 2)) + y, 0);

	for (int i = 1 ; i < 100;i++)
	{
		temp = i * 360 / 100;
		radian = (float)temp * DX_PI / 180.0f;
		x = cosf(radian) * (scale.y / 2);
		y = sinf(radian) * (scale.y / 2);
		VECTOR Pos2 = VGet(position.x + x, (position.y + (scale.y / 2)) + y, 0);
		DrawLine3D(Pos1, Pos2, color) ;
		Pos1 = Pos2;
	}
}

void BaseEntity::Teardown()
{
	
}

void BaseEntity::DecreaseRunawayCount()
{
	// 暴走カウンターを減少させる
	runawayCount--;
	if (runawayCount < 0)
	{
		runawayCount = 0;
		return;
	}
	pRunawayUI->SetText(std::to_string(runawayCount));
	// 暴走カウンターが0になったら、暴走イベントを発生させる
	if (runawayCount > 0) return;
	RunawayCallback();
	RunawayEvent();
}

void BaseEntity::SetRunawayUI(UIButton* setUI)
{
	pRunawayUI = setUI;
	pRunawayUI->SetText(std::to_string(runawayCount));
}