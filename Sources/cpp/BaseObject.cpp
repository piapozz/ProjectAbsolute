#include "../header/BaseObject.h"

void BaseObject::Init()
{
   // �K�v�ɉ����ď������R�[�h��ǉ�
}

void BaseObject::Draw()
{
   // �K�v�ɉ����ĕ`��R�[�h��ǉ�
}

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = -1;
	position = Vector2::zero();
}