#include "../header/InputManager.h"
#include "../header/UIScreenButton.h"
#include "../header/ObjectFactory.h"

InputManager::InputManager()
{
	_isLPressed = false;
	_isRPressed = false;
	// カーソルの非表示
	SetMouseDispFlag(FALSE);
	_cursorColor = GetColor(255, 0, 0);
	_onCursorObject = nullptr;
	Vector2 centorScreen = Vector2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	Vector2 size = Vector2(_CURSOR_SIZE, _CURSOR_SIZE);
	LayerSetting layerSetting = {true, false, Layer::FRONT};
	_cursorObject = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(centorScreen, size, true, layerSetting);
}

InputManager::~InputManager()
{

}

int InputManager::CheckClickState()
{
	// マウスの状態を取得
	int mouseInput, posX, posY, isUp = -1;
	if (GetMouseInputLog2(&mouseInput, &posX, &posY, &isUp, TRUE) < 0) return -1;
	// クリック情報を保持
	if (mouseInput == MOUSE_INPUT_LEFT)
	{
		_LClickState = isUp;
		if (isUp == MOUSE_INPUT_LOG_DOWN)
		{
			_isLPressed = true;
			_oldLClickScreenPos = Vector2((float)posX, (float)posY);
		}
		else if (isUp == MOUSE_INPUT_LOG_UP)
			_isLPressed = false;
	}
	else if (mouseInput == MOUSE_INPUT_RIGHT)
	{
		_RClickState = isUp;
		if (isUp == MOUSE_INPUT_LOG_DOWN)
		{
			_isRPressed = true;
			_oldRClickScreenPos = Vector2((float)posX, (float)posY);
		}
		else if (isUp == MOUSE_INPUT_LOG_UP)
			_isRPressed = false;
	}
	return mouseInput;
}

Vector2 InputManager::GetCursorScreenPos()
{
	int posx, posy;
	GetMousePoint(&posx, &posy);
	return Vector2((float)posx, (float)posy);
}

void InputManager::ExecuteCallback()
{
	// カーソル座標の取得
	Vector2 cursorScreenPos = GetCursorScreenPos();
	// クリックの状態を確認
	int currentMouseInput = CheckClickState();
	// カーソルが乗っているとき
	if (_OnCursorAction != NULL)
	{
		_OnCursorAction(cursorScreenPos);
	}
	// 左クリック
	if (currentMouseInput == MOUSE_INPUT_LEFT)
	{
		if (_LPushAction != NULL && _LClickState == MOUSE_INPUT_LOG_DOWN)
			_LPushAction(cursorScreenPos);
		else if (_LReleaseAction != NULL && _LClickState == MOUSE_INPUT_LOG_UP)
			_LReleaseAction(cursorScreenPos, _oldLClickScreenPos);
	}
	// ドラックしているとき
	if (_LDrackAction != NULL && _isLPressed)
		_LDrackAction(cursorScreenPos, _oldLClickScreenPos);
	// 右クリック
	if (currentMouseInput == MOUSE_INPUT_RIGHT)
	{
		if (_RPushAction != NULL && _RClickState == MOUSE_INPUT_LOG_DOWN)
			_RPushAction(cursorScreenPos);
		else if (_RReleaseAction != NULL && _RClickState == MOUSE_INPUT_LOG_UP)
			_RReleaseAction(cursorScreenPos, _oldRClickScreenPos);
	}
	// ドラックしているとき
	if (_RDrackAction != NULL && _isRPressed)
		_RDrackAction(cursorScreenPos, _oldRClickScreenPos);
	// ホイールを回転させたときの処理
	int wheelRot = GetMouseWheelRotVol();
	if (_WheelRotAction != NULL && wheelRot != 0)
		_WheelRotAction(cursorScreenPos, wheelRot);
	// Escapeキーを押したときの処理
	if (_EscapePushAction != NULL && CheckHitKey(KEY_INPUT_ESCAPE))
		_EscapePushAction();
}

void InputManager::UpdateCursor()
{
	// カーソル座標の取得
	Vector2 cursorScreenPos = GetCursorScreenPos() + Vector2(_CURSOR_SIZE / 2, _CURSOR_SIZE /2);
	_cursorObject->SetPosition(cursorScreenPos);
}

bool InputManager::IsLeftClick(Vector2 pos)
{
	float distanceClick = (pos - _oldLClickScreenPos).size();
	return distanceClick <= _CLICK_MARGIN;
}

bool InputManager::IsRightClick(Vector2 pos)
{
	float distanceClick = (pos - _oldRClickScreenPos).size();
	return distanceClick <= _CLICK_MARGIN;
}