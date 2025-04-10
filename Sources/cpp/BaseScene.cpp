#include "../header/BaseScene.h"

// コンストラクタ
BaseScene::BaseScene() 
{

}

// デストラクタ
BaseScene::~BaseScene() 
{

}

// フォントサイズをリセットしながら文字の描画
void DrawString(string text, int fontSize, Vector2 position)
{
	// 指定されたフォントサイズに変更
	SetFontSize(fontSize);
	// 変更されたフォントサイズで文字を描画
	DrawFormatString(position.x, position.y, COLOR_WHITE, text.c_str());
	// デフォルトに戻す
	SetFontSize(FONT_DEFAULT);
}