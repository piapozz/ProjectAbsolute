#pragma once
#include "../header/BaseController.h"

class ControllerEntityTriangle: public BaseController
{
public:
	ControllerEntityTriangle(){
		_startCount = GetNowCount();
	}
	ControllerEntityTriangle(BaseCharacter* character): BaseController(character){
		_startCount = GetNowCount();
	};
	~ControllerEntityTriangle(){
	};

	void UpdateAI() override;
	void DecideState() override;

private:
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

};