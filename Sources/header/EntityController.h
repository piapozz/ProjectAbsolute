#pragma once
#include "../header/CharacterController.h"
#include "../header/BaseOfficer.h"

class EntityController: public CharacterController
{
public:
	EntityController(){
	}
	EntityController(BaseCharacter* character): CharacterController(character){
		CharacterController::character = character;
	};
	~EntityController(){
	};

	void UpdateAI() override;
	void DecideState() override;

private:

};