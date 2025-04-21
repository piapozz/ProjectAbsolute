#include "../header/BaseUI.h"

void BaseUI::Init(Vector2 setPosition, Vector2 setSize)
{
	fontHandle = CreateFontToHandle("ÇlÇr ÉSÉVÉbÉN", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE); 
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::UI;
	layer = Layer::OBJECT;
}

void BaseUI::Proc()
{
	// ÉAÉbÉvÉfÅ[Ég
	BaseObject::Proc();
}

void BaseUI::Draw()
{
	// ï`âÊ
	BaseObject::Draw();

	// éläpÇï`âÊ
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

void BaseUI::Teardown()
{
	// îjä¸
	BaseObject::Teardown();
}

void BaseUI::SetActive(bool active)
{
	if (active)
	{
		layer = Layer::UI;
	}
	else
	{
		layer = Layer::NONE_DRAW;
	}
}