#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * �X�^���o�C�t�F�[�Y
 */
class PhaseStandby : public BasePhase
{
public:
	PhaseStandby() {}
	~PhaseStandby() {};

	void Init() override;
	void Teardown() override {};

protected:

private:

};

