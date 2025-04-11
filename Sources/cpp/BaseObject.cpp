#include "../header/BaseObject.h"

void BaseObject::Init()
{
   // 必要に応じて初期化コードを追加
}

void BaseObject::Draw()
{
   // 必要に応じて描画コードを追加
}

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = -1;
	position = Vector2::zero();
}