#include "../header/UIImage.h"

void UIImage::Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting)
{
	BaseUI::Init(setPosition, setSize, layerSetting);
}

void UIImage::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
}

void UIImage::Draw()
{
	// �`��
	BaseObject::Draw();

	// �l�p��`��
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

void UIImage::Teardown()
{
	// �j��
	BaseUI::Teardown();
}
