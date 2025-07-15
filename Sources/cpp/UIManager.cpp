#include "../header/ObjectFactory.h"
#include "../header/UIManager.h"
#include "../header/UIScreenButton.h"
#include "../header/UIEntity.h"
#include "../header/UIOfficer.h"

UIManager::UIManager()
{
	for (int i = 0; i < FONT_SIZE_MAX; i++)
	{
		_fontHandle[i] = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", i, 1);
	}
}

UIManager::~UIManager()
{
	for (int i = 0; i < FONT_SIZE_MAX; i++)
	{
		DeleteFontToHandle(_fontHandle[i]);
	}
}

int UIManager::GetFontHandle(int size)
{
	if (size < 0 || size > FONT_SIZE_MAX) return -1;

	return _fontHandle[size];
}