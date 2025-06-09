#include "../header/Cursor.h"
#include "../header/InputManager.h"

void Cursor::Proc()
{
	// �J�[�\���̍��W�ړ�
	Vector2 cursorScreenPos = InputManager::Instance().GetCursorScreenPos() + Vector2(CURSOR_SIZE / 2, CURSOR_SIZE /2);
	position = cursorScreenPos;
}

void Cursor::Draw()
{
	DrawUIBox(GetColor(128, 128, 128));
	DrawUIText();
	BaseUIScreen::Draw();
}