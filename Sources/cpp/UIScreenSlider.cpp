#include "../header/UIScreenSlider.h"
#include "../header/CameraController.h"

void UIScreenSlider::Init(Vector2 setPosition, Vector2 setSize)
{
	_screenPos = setPosition;
	_color = -1;
	// �X�e�[�W���W�ɕϊ�
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
	// ������
	BaseUI::Init(setPosition, setSize);
}

void UIScreenSlider::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
}

void UIScreenSlider::Draw()
{
	// �l�p��`��
	int x1 = position.x - objectSize.x / 2;
	int y1 = position.y - objectSize.y / 2;
	int x2 = x1 + (objectSize.x * _value);
	int y2 = position.y + objectSize.y / 2;

	// 2D�\��
	DrawBoxAA(x1, y1, x2, y2, _color, true);

	DrawUIBox();
	DrawUIText();

	// �X�e�[�W���W�ɕϊ�
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void UIScreenSlider::Teardown()
{
	// �j��
	BaseUI::Teardown();
}