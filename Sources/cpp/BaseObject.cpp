#include "../header/BaseObject.h"

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = Layer::INVALID;
	position = Vector2::zero();
}

bool BaseObject::IsSamePos(Vector2 pos)
{
	// 位置が同じかどうか
	float posMinX = position.x - objectSize.x / 2;
	float posMaxX = position.x + objectSize.x / 2;
	float posMinY = position.y - objectSize.y / 2;
	float posMaxY = position.y + objectSize.y / 2;
	return (pos.x >= posMinX && pos.x <= posMaxX && pos.y >= posMinY && pos.y <= posMaxY);
}

bool BaseObject::IsSameRect(Vector2 pos, Vector2 size)
{
	float left = pos.x - (size.x / 2);
	float right = pos.x + (size.x / 2);
	if (left > right)
	{
		float temp = left;
		left = right;
		right = temp;
	}
	float up = pos.y - (size.y / 2);
	float down = pos.y + (size.y / 2);
	if (up < down)
	{
		float temp = up;
		up = down;
		down = temp;
	}

	float posMinX = position.x - objectSize.x / 2;
	float posMaxX = position.x + objectSize.x / 2;
	float posMinY = position.y - objectSize.y / 2;
	float posMaxY = position.y + objectSize.y / 2;

	bool xSame = (posMinX > left && right > posMinX) || (posMaxX > left && right > posMaxX);
	bool ySame = (posMinY > down && up > posMinY) || (posMaxY > down && up > posMaxY);

	return xSame && ySame;
}