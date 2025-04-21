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
	bool Proc() override;
	void Teardown() override {};

protected:

private:

};

