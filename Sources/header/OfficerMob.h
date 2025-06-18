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
	OfficerMob(OfficerInitData data, int setOfficerID, LayerSetting layerSetting, Vector2 position)
		: BaseOfficer(layerSetting)
	{
		Init(data, setOfficerID, position);
	};
	~OfficerMob(){
	};

	static std::string StaticTypeName() {
		return "OfficerMob";
	}

	void Init(OfficerInitData data, int setOfficerID, Vector2 position) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
