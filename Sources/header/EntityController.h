#pragma once
#include "../header/BaseController.h"
#include "../header/BaseOfficer.h"

class EntityController: public BaseController
{
public:
	EntityController(){
	}
	EntityController(BaseCharacter* character): BaseController(character){
		BaseController::character = character;
	};
	~EntityController(){
	};

	void UpdateAI() override;
	void DecideState() override;

private:

};