#include "../header/SectionConnect.h"

#include "../header/Const.h"

void SectionConnect::Init(Vector2 setPosition, int setSize)
{
	// ������
	BaseSection::Init(setPosition, setSize);
	sectionType = SectionType::CONNECT;
	layer = Layer::OBJECT;
}

void SectionConnect::Proc()
{
	// �A�b�v�f�[�g
	BaseSection::Proc();
}

void SectionConnect::Draw()
{
	// �`��
	BaseSection::Draw();

	// �l�p��`��
	int x1 = position.x + SECTION_SIZE / 2;
	int y1 = position.y + SECTION_SIZE / 2;
	int x2 = position.x - SECTION_SIZE / 2;
	int y2 = position.y - SECTION_SIZE / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(0, 255, 255)) ;
	DrawLine3D(Pos2, Pos3, GetColor(0, 255, 255)) ;
	DrawLine3D(Pos3, Pos4, GetColor(0, 255, 255)) ;
	DrawLine3D(Pos4, Pos1, GetColor(0, 255, 255)) ;
}

void SectionConnect::Teardown()
{
	// �j��
	BaseSection::Teardown();
}