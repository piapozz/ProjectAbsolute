#include "../header/Cursor.h"
#include "../header/InputManager.h"
#include "../header/ObjectFactory.h"

void Cursor::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_pImage = ObjectFactory::Instance().CreateWithArgs<UIScreenImage>(setTransform, fill, layerSetting);
}

void Cursor::Proc()
{
	// カーソルの座標移動
	Vector2 cursorScreenPos = InputManager::Instance().GetCursorScreenPos() + Vector2(CURSOR_SIZE / 2, CURSOR_SIZE /2);
	transform.position = cursorScreenPos;
	_pImage->SetPosition(cursorScreenPos);
}

void Cursor::Draw()
{
	_pImage->DrawUIBox(GetColor(128, 128, 128));
	BaseUIScreen::Draw();
}