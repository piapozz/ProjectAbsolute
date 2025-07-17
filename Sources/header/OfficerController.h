#pragma once
#include "../header/BaseController.h"
#include "../header/BaseOfficer.h"

class OfficerController: public BaseController 
{
public:
	OfficerController(){
		_startCount = GetNowCount();
	}
	OfficerController(BaseCharacter* character): BaseController(character){
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
	/// 一定時間待つ
	/// </summary>
	/// <returns></returns>
	bool WaitUntilCount();
	/// <summary>
	/// 今いる部屋の中でランダムな座標を返す
	/// </summary>
	/// <returns></returns>
	Vector2 GetRandomPositionInRoom();
	/// <summary>
	/// 敵がいるか確認
	/// </summary>
	BaseCharacter* CheckHostility();

	void UpdateIdleState() override;
	void UpdateMoveState() override;
	void UpdateFightState() override;

	void UpdatePanicState();

};