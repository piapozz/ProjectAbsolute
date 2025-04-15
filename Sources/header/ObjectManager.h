#pragma once
#include "Const.h"
#include <vector>
#include "BaseObject.h"
/*
* Ishihara
* オブジェクトの管理
*/
class ObjectManager
{
public:
	ObjectManager() {}
	~ObjectManager() {}

	/// <summary>
	/// 初期化
	/// </summary>
	static void Init();
	/// <summary>
	/// 更新
	/// </summary>
	static void Update();
	/// <summary>
	/// 描画
	/// </summary>
	static void Draw();
	/// <summary>
	/// オブジェクトの追加
	/// </summary>
	static void AddObject(BaseObject* obj);
	/// <summary>
	/// オブジェクトの削除
	/// </summary>
	static void RemoveObject(BaseObject* obj);
	// オブジェクトのリスト
	static std::vector<BaseObject*> _objectList;
};

