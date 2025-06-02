#include "../header/BaseUIScreen.h"
#include "../header/CameraController.h"
#include "../header/ObjectManager.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize)
{
	_text == "";
	_textColor = -1;
	_screenPos = setPosition;
	// �X�e�[�W���W�ɕϊ�
	position = CameraController::GetScreen2StagePos(_screenPos);
	fontHandle = CreateFontToHandle("�l�r �S�V�b�N", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE);
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SCREEN_UI;
	layer = Layer::OBJECT;
	ObjectManager::instance->AddObject(this);
	textSize = 100;
}

void BaseUIScreen::Proc()
{
	// �A�b�v�f�[�g
	BaseObject::Proc();
}

void BaseUIScreen::Draw()
{
	// �`��
	BaseObject::Draw();
	DrawUIBox();
	DrawUIText();
}

void BaseUIScreen::Teardown()
{
	// �j��
	BaseObject::Teardown();
}

void BaseUIScreen::DrawUIBox()
{
	// �l�p��`��
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	DrawBoxAA(x1, y1, x2, y2, GetColor(255, 255, 255), FALSE) ;
}

void BaseUIScreen::DrawUIText()
{
	if (_text == "") return;
	// �e�L�X�g
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}