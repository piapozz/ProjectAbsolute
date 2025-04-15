#include "../header/BasePhase.h"
#include "DxLib.h"

void BasePhase::ProcLoop()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		if (Proc()) break;

		ObjectManager::Update();
		ObjectManager::Draw();
	}
}