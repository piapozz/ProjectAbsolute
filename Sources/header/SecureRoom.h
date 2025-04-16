#pragma once
#include "../header/BaseSection.h"
#include "../header/BaseEntity.h"

/*
 * Sakakura
 * 収容室
 */
class SecureRoom: public BaseSection
{
public:
	SecureRoom()
		:_isMeltdown(false), _meltdownCount(0){};
	SecureRoom(BaseEntity* pEntity)
		:_pEntity(pEntity), _isMeltdown(false), _meltdownCount(0){}
	~SecureRoom(){ Teardown(); }

	void Init(Vector2 position, int size) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	/// <summary>
	/// メルトダウンの開始
	/// </summary>
	void StartMeltdown();
	void SetEntity(BaseEntity* pEntity){ _pEntity = pEntity; }

private:
	// メルトダウンのカウント数
	int _MELTDOWN_COUNT = 60 * 60;
	// 収容しているエンティティー
	BaseEntity* _pEntity;
	bool _isMeltdown;
	int _meltdownCount;

	/// <summary>
	/// メルトダウンのカウントをする
	/// </summary>
	void MeltdownProc();
};

