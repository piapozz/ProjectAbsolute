#include "../header/UIScreenButton.h"
#include "../header/CameraController.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize, bool fill)
{
	// ������
	BaseUIScreen::Init(setPosition, setSize, fill);
}

void UIScreenButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
}

void UIScreenButton::Draw()
{
	DrawUIBox(GetColor(128, 128, 128));
	DrawUIText();
	BaseUIScreen::Draw();
}

void UIScreenButton::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}