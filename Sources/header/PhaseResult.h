#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * ���U���g�t�F�[�Y
 */
class PhaseResult : public BasePhase
{
public:
	PhaseResult() { Init(); }
	~PhaseResult() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:

private:

};

