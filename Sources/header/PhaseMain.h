#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * ���C���t�F�[�Y
 */
class PhaseMain : public BasePhase
{
public:
	PhaseMain() { Init(); }
	~PhaseMain() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:

};

