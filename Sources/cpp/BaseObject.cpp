#include "../header/BaseObject.h"

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = Layer::INVALID;
	position = Vector2::zero();
}