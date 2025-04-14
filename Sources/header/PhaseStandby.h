#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * スタンバイフェーズ
 */
class PhaseStandby : public BasePhase
{
public:
	PhaseStandby() { Init(); }
	~PhaseStandby() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:

};

