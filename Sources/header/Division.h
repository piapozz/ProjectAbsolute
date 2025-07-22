#pragma once
#include "Const.h"
#include "BaseSection.h"

class SecureRoom;
class BaseEntity;
/*
区画番号
リスポーン地点
Sectionの保持
ランダムな部屋の座標を返す
*/

class Division
{
public:
	// コンストラクタ
	Division(BaseSection* respawnPoint)
		:_respawnPoint(respawnPoint) {}

	// デストラクタ
	~Division() = default;

	// 部屋の設定
	void SetRoomList(const std::vector<BaseSection*>& roomList) {
		_roomList = roomList;
	}
	// セキュアルームの設定
	void SetSecureRoomList(const std::vector<SecureRoom*>& secureRoomList) {
		_secureRoomList = secureRoomList;
	}

	// 区画番号を設定
	void SetDivisionIndex(int divisionIndex) {
		_divisionIndex = divisionIndex;
	}

	void SetEntity(BaseEntity* entity, int index);

	// 区画番号を取得
	int GetDivisionIndex() const { return _divisionIndex; }
	// リスポーン地点を取得
	BaseSection* GetRespawnPoint() const { return _respawnPoint; }
	// ランダムな部屋の座標を返す
	BaseSection* GetRandomSection();
	std::vector<BaseSection*> GetRoomList();

	std::vector<SecureRoom*> GetSecureRoomList() const {
		return _secureRoomList;
	}

private:
	// 区画番号
	int _divisionIndex;
	// リスポーン地点
	BaseSection* _respawnPoint; 

	std::vector<BaseSection*> _roomList;
	std::vector<SecureRoom*> _secureRoomList;
};

