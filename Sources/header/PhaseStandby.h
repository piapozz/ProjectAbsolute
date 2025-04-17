#pragma once
#include "BasePhase.h"

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
	void LClickInputProc(Vector2 pos, Vector2 oldPos) override;

private:

};

