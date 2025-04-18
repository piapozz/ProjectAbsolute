#include "../header/BaseSection.h"

void BaseSection::Init(Vector2 setPosition, int setSize)
{
	// ������
	sectionType = SectionType::INVALID;
	position = setPosition;
	size = setSize;
	objectSize = Vector2(SECTION_SIZE * size, SECTION_SIZE * size);
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