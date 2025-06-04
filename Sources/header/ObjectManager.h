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
	static ObjectManager& Instance() {
		static ObjectManager instance;
		return instance;
	}

	ObjectManager() {}
	~ObjectManager() {}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// オブジェクトの追加
	/// </summary>
	void AddObject(BaseObject* obj);
	/// <summary>
	/// オブジェクトの削除
	/// </summary>
	void RemoveObject(BaseObject* obj);
	/// <summary>
	/// オブジェクトの全削除
	/// </summary>
	void AllClear();
	/// <summary>
	/// オブジェクトの検索(一番上)
	/// </summary>
	/// <returns></returns>
	BaseObject* FindPosObject(Vector2 pos);
	/// <summary>
	/// オブジェクトの検索(タイプ指定)
	/// </summary>
	/// <returns></returns>
	BaseObject* FindPosObject(Vector2 pos, ObjectType type);
	/// <summary>
	/// オブジェクトの検索(全部)
	/// </summary>
	/// <returns></returns>
	std::vector<BaseObject*> FindRectAllObject(Vector2 pos, Vector2 size, ObjectType type);
	/// <summary>
	/// ゲーム速度の変更
	/// </summary>
	/// <param name="setGameSpeed"></param>
	void ChangeGameSpeed(int setGameSpeed){
		_gameSpeed = setGameSpeed;
	}
private:
	// オブジェクトのリスト
	std::vector<std::vector<BaseObject*>> _objectList;
	// ゲームスピード
	int _gameSpeed;
};

