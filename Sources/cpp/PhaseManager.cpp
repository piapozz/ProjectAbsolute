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
	// ���݂̃V�[�����󂶂�Ȃ�������A�V�[���̏���j������
	delete(_currentPhase);

	// �����̃V�[���ɐ؂�ւ���
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
	// �����������Ă���
	_currentPhase->Init();
	// �R�[���o�b�N��ݒ�
	_currentPhase->SetChangePhaseCallback([this](PhaseName nextPhase) { this->ChangePhase(nextPhase); });
}