#include "../header/SectionRoom.h"
#include "../header/Const.h"
#include <math.h>

void SectionRoom::Init(Vector2 setPosition, int setSize)
{
	// 初期化
	BaseSection::Init(setPosition, setSize);
	sectionType = SectionType::ROOM;
	layer = Layer::OBJECT;
}

void SectionRoom::Proc()
{
	// アップデート
	BaseSection::Proc();
}

void SectionRoom::Draw()
{
	// 描画
	BaseSection::Draw();

	// 四角を描画
	int x1 = position.x + SECTION_SIZE / 2 + (SECTION_SIZE * (size / 2 - 1));
	int y1 = position.y + SECTION_SIZE / 2 + (SECTION_SIZE * (size / 2 - 1));
	int x2 = position.x - SECTION_SIZE / 2;
	int y2 = position.y - SECTION_SIZE / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255)) ;
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255)) ;
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255)) ;
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255)) ;
}

void SectionRoom::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}