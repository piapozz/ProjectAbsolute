#include "../header/InputManager.h"

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{

}

bool InputManager::IsClick(int button)
{
	// 無効値の場合即座に処理を抜ける
	if (button != MOUSE_INPUT_LEFT && button != MOUSE_INPUT_RIGHT) return false;
	// マウスの状態を取得
	int mouseInput, posX, posY, isUp;
	GetMouseInputLog2(&mouseInput, &posX, &posY, &isUp, TRUE);
	// 押されたときのカーソル座標を保持
	if (!isUp)
	{
		if (mouseInput == MOUSE_INPUT_LEFT)
			_oldLClickScreenPos = Vector2((float)posX, (float)posY);
		else if (mouseInput == MOUSE_INPUT_RIGHT)
			_oldRClickScreenPos = Vector2((float)posX, (float)posY);
	}

	return button == mouseInput && isUp;
}

Vector2 InputManager::GetCursorScreenPos()
{
	int posx, posy;
	GetMousePoint(&posx, &posy);
	return Vector2((float)posx, (float)posy);
}

Vector2 InputManager::GetCursorWorldPos(Vector2 screenPos)
{
	VECTOR screenVec = VGet(screenPos.x, screenPos.y, 0.5f);
	VECTOR worldVec = ConvScreenPosToWorldPos(screenVec);
	return Vector2(worldVec.x, worldVec.y);
}

void InputManager::ExecuteCallback()
{
	// カーソル座標の取得
	Vector2 cursorScreenPos = GetCursorScreenPos();

	// 左クリックを押したときの処理
	if (_LPushAction != NULL && IsClick(MOUSE_INPUT_LEFT))
		_LPushAction(cursorScreenPos);
	// 右クリックを押したときの処理
	if (_RPushAction != NULL && IsClick(MOUSE_INPUT_RIGHT))
		_RPushAction(cursorScreenPos);
	// 左クリックを離したときの処理
	if (_LReleaseAction != NULL && IsClick(MOUSE_INPUT_LEFT))
		_LReleaseAction(cursorScreenPos, _oldLClickScreenPos);
	// 右クリックを離したときの処理
	if (_RReleaseAction != NULL && IsClick(MOUSE_INPUT_RIGHT))
		_RReleaseAction(cursorScreenPos, _oldRClickScreenPos);
	// ホイールを回転させたときの処理
	int wheelRot = GetMouseWheelRotVol();
	if (_WheelRotAction != NULL && wheelRot != 0)
		_WheelRotAction(cursorScreenPos, wheelRot);
	// Escapeキーを押したときの処理
	if (_EscapePushAction != NULL && CheckHitKey(KEY_INPUT_ESCAPE))
		_EscapePushAction();
}
