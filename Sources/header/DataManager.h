#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../header/Const.h"

/*
 * Sein
 * 外部データに分離された情報を管理
 * Json: その日の状況やプレイヤーのパラメータを管理
 * Csv : 部屋の配置のみを管理
 */
class DataManager
{
public:

	static DataManager& Instance() {
		static DataManager instance;
		return instance;
	}

	DataManager(){
		_energy = 0;
		_money = 0;
	}
	~DataManager();

	/// <summary>
	/// Csvをロード
	/// </summary>
	void CsvLoad();
	/// <summary>
	/// Jsonをロード
	/// </summary>
	void JsonLoad();
	/// <summary>
	/// 引数で渡されたファイルをセーブ
	/// </summary>
	void SaveFile();

	void SetEntityData(std::vector<EntityManagementData> data){
		_entityData = data;
	}
	void SetOfficerData(std::vector<OfficerInitData> data){
		_officerData = data;
	}
	void SetMoney(int money) {
		_money = money;
	}
	void SetEnergy(int energy) {
		_energy = energy;
	}

	/// <summary>
	/// エンティティのデータを取得
	/// </summary>
	std::vector<EntityManagementData> GetEntityData() const {
		return _entityData;
	}
	/// <summary>
	/// オフィサーのデータを取得
	/// </summary>
	std::vector<OfficerInitData> GetOfficerData() const {
		return _officerData;
	}

	/// <summary>
	/// 所持金を取得
	/// </summary>
	int GetMoney() const {
		return _money;
	}
	int GetEnergy() const {
		return _energy;
	}

private:
	std::vector<EntityManagementData> _entityData;
	std::vector<OfficerInitData> _officerData;

	int _money;
	int _energy;
};
