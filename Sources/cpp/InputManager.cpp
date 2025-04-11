#include "../header/InputManager.h"

InputManager::InputManager()
{
	cursorPos = {0,0};
}

InputManager::~InputManager()
{

}

/// <summary>
/// クリックが押されているかを判定
/// </summary>
/// <param name="button"></param>
/// <returns></returns>
bool InputManager::CheckClick(MouseButton button)
{
	// 無効値の場合即座に処理を抜ける
	if(button == MouseButton::NONE) return false;
	// マウスの状態を取得
	int mouseInput = GetMouseInput();
	// 判定結果をキャッシュ
	bool onClick = (mouseInput & button) && !(oldMouseInput & button);
	oldMouseInput = mouseInput;

	return onClick;
}

/// <summary>
/// カーソル情報の更新
/// </summary>
/// <param name="mouseStatus"></param>
void InputManager::UpdataMouseCursor(MouseStatus mouseStatus)
{
	GetMousePoint(&mouseStatus.CURSOR_POS_X,&mouseStatus.CURSOR_POS_Y);
}

/// <summary>
/// コールバックで設定された関数を実行
/// </summary>
void InputManager::ExecuteCallback()
{
	if(callbackFunc == NULL) return;
	callbackFunc();
}

InputManager::MouseStatus InputManager::GetCursorPos() { return cursorPos; }
void InputManager::SetCallback(std::function<void()> callback) { callbackFunc = callback; }