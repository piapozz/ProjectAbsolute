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
	OfficerMob(OfficerInitData data, int setOfficerID, LayerSetting layerSetting)
	{
		Init(data, setOfficerID, layerSetting);
	};
	~OfficerMob(){
	};

	static std::string StaticTypeName() {
		return "OfficerMob";
	}

	void Init(OfficerInitData data, int setOfficerID, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
