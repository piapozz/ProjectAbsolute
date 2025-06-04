#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * ÉvÉåÉCÉÑÅ[Ç™êßå‰Ç≈Ç´Ç»Ç¢Officer
 */
class OfficerMob : public BaseOfficer
{
public:
	OfficerMob(){
	};
	OfficerMob(OfficerInitData data, int setOfficerID)
	{
		Init(data, setOfficerID);
	};
	~OfficerMob(){
	};

	static std::string StaticTypeName() {
		return "OfficerMob";
	}

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
