#include "../header/BaseObject.h"

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = Layer::INVALID;
	position = Vector2::zero();
}

bool BaseObject::IsSamePos(Vector2 pos)
{
	// ˆÊ’u‚ª“¯‚¶‚©‚Ç‚¤‚©
	float posMinX = position.x - objectSize.x / 2;
	float posMaxX = position.x + objectSize.x / 2;
	float posMinY = position.y - objectSize.y / 2;
	float posMaxY = position.y + objectSize.y / 2;
	return (pos.x >= posMinX && pos.x <= posMaxX && pos.y >= posMinY && pos.y <= posMaxY);
}