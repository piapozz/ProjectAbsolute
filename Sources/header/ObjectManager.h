#pragma once
#include <vector>
/*
* Ishihara
* オブジェクトの管理
*/
class BaseObject;
class ObjectManager
{
public:
	enum Layer
	{
		LAYER_NONE = -1,
		LAYER_NONEDRAW,
		LAYER_BACKGROUND,
		LAYER_OBJECT,
		LAYER_PLAYER,
		LAYER_ENEMY,
		LAYER_EFFECT,
		LAYER_UI,

		LAYER_MAX
	};

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
private:
	// オブジェクトのリスト
	std::vector<BaseObject*> _objectList;
};

