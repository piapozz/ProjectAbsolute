#pragma once
#include "BasePhase.h"

/*
 * Sakakura
 * リザルトフェーズ
 */
class PhaseResult : public BasePhase
{
public:
	PhaseResult() {}
	~PhaseResult() {};

	void Init() override;
	void Teardown() override {};

protected:

private:

};

