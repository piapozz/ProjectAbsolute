#include "../header/BaseSection.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacter.h"

void BaseSection::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	sectionType = SectionType::INVALID;
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SECTION;
	layer = Layer::OBJECT;
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

	// 四角を描画
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));
}

void BaseSection::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}

std::vector<BaseCharacter*> BaseSection::GetCharacters() const
{
	// キャラクターの取得
	auto charas = ObjectManager::Instance().FindRectObject(position, objectSize, ObjectType::CHARACTER);
	std::vector<BaseCharacter*> characters;
	for (BaseObject* obj : charas)
	{
		if (obj->GetType() == ObjectType::CHARACTER)
		{
			characters.push_back(static_cast<BaseCharacter*>(obj));
		}
	}
	return characters;
}