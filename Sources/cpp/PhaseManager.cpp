#include "../header/PhaseManager.h"
#include "../header/ObjectManager.h"
#include "../header/EntityManager.h"
#include "../header/InputManager.h"
#include "../header/DataManager.h"

void PhaseManager::Init()
{
	_currentDay = 0;
	ChangePhase(PhaseName::SELECT);
	DataManager::Instance().SetMoney(1000);
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

	ObjectManager::Instance().AllClear();
	InputManager::Instance().Teardown();

	// 引数のシーンに切り替える
	switch (nextPhase)
	{
		case PhaseName::SELECT:
			_currentDay++;
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
	// コールバックを設定
	_currentPhase->SetChangePhaseCallback([this](PhaseName nextPhase) { this->ChangePhase(nextPhase); });
	_currentPhase->SetChangeSceneCallback([this](SceneName nextScene) { this->_ChangeScene(nextScene); });
	_currentPhase->SetGetDayCallback([this]() { return _currentDay; });
	// 初期化をしておく
	_currentPhase->Init();
	InputManager::Instance().Init();
}