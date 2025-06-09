#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * スタンバイフェーズ
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

