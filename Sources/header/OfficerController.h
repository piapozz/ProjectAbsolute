#pragma once
#include "../header/CharacterController.h"
#include "../header/BaseOfficer.h"

class OfficerController: public CharacterController 
{
public:
	OfficerController(){
		_startCount = GetNowCount();
	}
	OfficerController(BaseCharacter* character): CharacterController(character){
		_startCount = GetNowCount();
		officer = static_cast<BaseOfficer*>(character);
	};
	~OfficerController(){
	};

	void UpdateAI() override;
	void DecideState() override;

private:
	BaseOfficer* officer;
	float _startCount;
	const float _waitCount = 3000;

	/// <summary>
	/// ˆê’èŠÔ‘Ò‚Â
	/// </summary>
	/// <returns></returns>
	bool WaitUntilCount();
	/// <summary>
	/// ¡‚¢‚é•”‰®‚Ì’†‚Åƒ‰ƒ“ƒ_ƒ€‚ÈÀ•W‚ğ•Ô‚·
	/// </summary>
	/// <returns></returns>
	Vector2 GetRandomPositionInRoom();

	void UpdateIdleState() override;
	void UpdateMoveState() override;
	void UpdateFightState() override;

};