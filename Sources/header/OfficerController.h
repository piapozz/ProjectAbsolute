#pragma once
#include "../header/CharacterController.h"

class BaseOfficer;

/*
 * Sein
 * Officer�̊��N���X
 */
class OfficerController : public CharacterController
{
public:
	OfficerController(){};
	OfficerController(BaseCharacter& character) {
		officer = dynamic_cast<BaseOfficer*>(&character);
	}
	~OfficerController(){};

	void UpdateAI() override;
	void DecideState() override;

protected:

private:
	BaseOfficer* officer;
	int _startCount = 0;
	const int _waitCount = 5000;

};