#include "../header/BaseSection.h"

void BaseSection::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	sectionType = SectionType::INVALID;
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SECTION;
}

void BaseSection::Proc()
{
	// アップデート
	BaseObject::Proc();
}

void BaseSection::Draw()
{
	// 描画
	BaseObject::Draw();
}

void BaseSection::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}