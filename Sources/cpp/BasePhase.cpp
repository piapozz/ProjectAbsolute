#include "../header/BasePhase.h"
#include  "../header/InputManager.h"
#include "DxLib.h"

void BasePhase::ProcLoop()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ObjectManager::instance->Update();
		if (Proc()) break;
		pInputManager->UpdateCursor();
		ObjectManager::instance->Draw();
	}
}