#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * �v���C���[������ł��Ȃ�Officer
 */
class OfficerMob : public BaseOfficer
{
public:
	OfficerMob();
	~OfficerMob();
	static std::string StaticTypeName() {
		return "OfficerMob";
	}

	std::string GetTypeName() const override {
		return StaticTypeName();
	}

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
