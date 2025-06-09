#include "../header/PhaseManager.h"
#include "../header/ObjectManager.h"

void PhaseManager::Init()
{
	ChangePhase(PhaseName::MAIN);
}

void PhaseManager::Teardown()
{
	_currentPhase->Teardown();
}

void PhaseManager::ChangePhase(PhaseName nextPhase)
{
	if (nextPhase == PhaseName::INVALID) return;
	// 現在のシーンが空じゃなかったら、シーンの情報を破棄する
	delete(_currentPhase);

	// 引数のシーンに切り替える
	switch (nextPhase)
	{
		case PhaseName::SELECT:
			_currentPhase = new PhaseSelect();
			break;
		case PhaseName::STANDBY:
			_currentPhase = new PhaseStandby();
			break;
		case PhaseName::MAIN:
			_currentPhase = new PhaseMain();
			break;
		case PhaseName::RESULT:
			_currentPhase = new PhaseResult();
			break;
		default: break;
	}
	// 初期化をしておく
	_currentPhase->Init();
	// コールバックを設定
	_currentPhase->SetChangePhaseCallback([this](PhaseName nextPhase) { this->ChangePhase(nextPhase); });
}