#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * ���C���t�F�[�Y
 */
class FaseMain : public BaseFase
{
public:
	FaseMain() { Init(); }
	~FaseMain() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:

};

