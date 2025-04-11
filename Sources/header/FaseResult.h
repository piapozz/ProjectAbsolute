#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * リザルトフェーズ
 */
class FaseResult : public BaseFase
{
public:
	FaseResult() { Init(); }
	~FaseResult() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:

};

