#include "../header/BaseSection.h"

void BaseSection::Init(Vector2 setPosition, Vector2 setSize)
{
	// ������
	sectionType = SectionType::INVALID;
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SECTION;
}

void BaseSection::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();
}

void BaseSection::Draw()
{
	// �`��
	BaseObject::Draw();
}

void BaseSection::Teardown()
{
	// �j��
	BaseObject::Teardown();
}