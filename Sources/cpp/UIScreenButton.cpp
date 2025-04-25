#include "../header/UIScreenButton.h"
#include "../header/CameraController.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize)
{
	_screenPos = setPosition;
	// �X�e�[�W���W�ɕϊ�
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
	// ������
	BaseUI::Init(stagePos, setSize);
}

void UIScreenButton::Proc()
{
	// �A�b�v�f�[�g
	BaseUI::Proc();
}

void UIScreenButton::Draw()
{
	DrawUIBox();
	DrawUIText();

	// �X�e�[�W���W�ɕϊ�
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void UIScreenButton::Teardown()
{
	// �j��
	BaseUI::Teardown();
}