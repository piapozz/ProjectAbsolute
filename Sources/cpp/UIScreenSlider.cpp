#include "../header/UIScreenSlider.h"
#include "../header/CameraController.h"

void UIScreenSlider::Init(Vector2 setPosition, Vector2 setSize, bool fill)
{
	BaseUIScreen::Init(setPosition, setSize, fill);
}

void UIScreenSlider::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
}

void UIScreenSlider::Draw()
{
	// �l�p��`��
	int x1 = position.x - objectSize.x / 2;
	int y1 = position.y - objectSize.y / 2;
	int x2 = x1 + (objectSize.x * _value);
	int y2 = position.y + objectSize.y / 2;

	DrawUIBox();
	DrawBoxAA(x1, y1, x2, y2, _color, TRUE);
	DrawUIText();

	BaseUIScreen::Draw();
}

void UIScreenSlider::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}