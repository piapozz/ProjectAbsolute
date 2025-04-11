#pragma once
#include "BaseFase.h"

/*
 * Sakakura
 * �X�^���o�C�t�F�[�Y
 */
class FaseStandby : public BaseFase
{
public:
	FaseStandby() { Init(); }
	~FaseStandby() {};

	void Init() override;
	bool Proc() override;
	void Teardown() override {};

protected:
	void InputProc() override;

private:

};

