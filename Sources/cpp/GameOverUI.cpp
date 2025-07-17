#include "../header/GameOverUI.h"
#include "../header/UIScreen.h"

GameOverUI::GameOverUI()
{
	BasePopupUI::Init();
	informationText->SetText(_INFORMATION_TEXT);
	button->SetText(_CONTINUE_TEXT);
}
