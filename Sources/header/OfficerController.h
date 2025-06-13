#pragma once
#include "../header/CharacterController.h"

class BaseOfficer;

/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class OfficerController : public CharacterController
{
public:
	OfficerController(){};
	OfficerController(BaseCharacter& character) {
		//officer = static_cast<BaseOfficer*>(&character);
	}
	~OfficerController(){};

	void UpdateAI() override;
	void DecideState() override;

	void UpdateIdleState();
	void UpdateMoveState();
	bool HasWaitedEnough();

protected:

private:
	BaseOfficer* officer;
	int _startCount = 0;
	const int _waitCount = 5000;

};