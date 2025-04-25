#include "../header/BaseUIScreen.h"
#include "../header/CameraController.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize)
{
	_text == "";
	_textColor = -1;
	// ������
	BaseUI::Init(setPosition, setSize);
}

void BaseUIScreen::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
}

void BaseUIScreen::Draw()
{
	// �`��
	BaseUI::Draw();
}

void BaseUIScreen::Teardown()
{
	// �j��
	BaseUI::Teardown();
}

void BaseUIScreen::DrawUIBox()
{
	// �l�p��`��
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	// 2D�\��
	DrawBoxAA(x1, y1, x2, y2, GetColor(255, 255, 255), false);

	// �X�e�[�W���W�ɕϊ�
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void BaseUIScreen::DrawUIText()
{
	if (_text == "") return;
	// �e�L�X�g
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text);
}