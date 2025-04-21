#include "../header/SectionRoom.h"
#include "../header/Const.h"
#include <math.h>
#include <algorithm> // std::max を使用するために必要

void SectionRoom::Init(Vector2 setPosition, Vector2 setSize)
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

   float valueX = (SECTION_SIZE) * (objectSize.x - 1);
   float valueY = (SECTION_SIZE) * (objectSize.y - 1);
   if (valueX < 0) valueX = 0;
   if (valueY < 0) valueY = 0;

   // 四角を描画
   int x1 = position.x + SECTION_SIZE / 2 + valueX;
   int y1 = position.y + SECTION_SIZE / 2;
   int x2 = position.x - SECTION_SIZE / 2;
   int y2 = position.y - SECTION_SIZE / 2 - valueY;

   VECTOR Pos1 = VGet(x1, y1, 0);
   VECTOR Pos2 = VGet(x2, y1, 0);
   VECTOR Pos3 = VGet(x2, y2, 0);
   VECTOR Pos4 = VGet(x1, y2, 0);

   DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
   DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
   DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
   DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));
}

void SectionRoom::Teardown()
{
	// 破棄
	BaseSection::Teardown();
}