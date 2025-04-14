#include "../header/InputManager.h"

InputManager::InputManager()
{
	_cursorPos = {0, 0};
}

InputManager::~InputManager()
{

}

void InputManager::OnClick(MouseButton button)
{
	// 無効値の場合即座に処理を抜ける
	if (button == MouseButton::NONE) return;
	// マウスの状態を取得
	int mouseInput = GetMouseInput();
	// 判定結果をキャッシュ
	bool onClick = (mouseInput & button) && !(_oldMouseInput & button);
	_oldMouseInput = mouseInput;

	if (onClick) ExecuteCallback();
}

void InputManager::UpdataMouseCursor(MouseStatus mouseStatus)
{
	GetMousePoint(&mouseStatus.CURSOR_POS_X, &mouseStatus.CURSOR_POS_Y);
}

void InputManager::ExecuteCallback()
{
	if (_ClickAction == NULL) return;
	_ClickAction();
}
