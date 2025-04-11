#pragma once
#include <iostream>
#include <fstream>

/*
 * Sein
 * 外部データに分離された情報を管理
 * Json: その日の状況やプレイヤーのパラメータを管理
 * Csv : 部屋の配置のみを管理
 */
class DataManager
{
public:

	DataManager();
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

};