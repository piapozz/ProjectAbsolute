#pragma once
#include "../header/BaseOfficer.h"
#include "../header/UISlider.h"

/*
 * Sein
 * �v���C���[������ł���Officer
 */
class OfficerPlayer : public BaseOfficer
{
public:
	OfficerPlayer();
	~OfficerPlayer();

	static std::string StaticTypeName() {
		return "OfficerPlayer";
	}

	std::string GetTypeName() const override {
		return StaticTypeName();
	}

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override;

private:
	// �X���C�_�[
	UISlider* slider;
};
