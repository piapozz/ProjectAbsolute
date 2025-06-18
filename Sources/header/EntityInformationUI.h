#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class UIScreenImage;

class EntityInformationUI : public BaseUIScreen
{
public:
	EntityInformationUI(){}
	EntityInformationUI(Transform setTransform, LayerSetting layerSetting);
	~EntityInformationUI(){}

	static std::string StaticTypeName() {
		return "EntityInformationUI";
	}

	void Draw();
	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }

private:
	UIScreenImage* _lockImage;
	UIScreenImage* _informationFrame;
	UIScreenText* _information;
	UIScreenImage* _image;
	UIScreenText* _name;
	UIScreenText* _id;
	UIScreenText* _hazardLevel;
	UIScreenText* _typeInformation;
	UIScreenText* _type;
	UIScreenText* _energyInformation;
	UIScreenText* _energy;
	UIScreenText* _operationInformation;
	UIScreenText* _goodOperationInformation;
	UIScreenText* _goodOperation;
	UIScreenText* _normalOperationInformation;
	UIScreenText* _normalOperation;
	UIScreenText* _badOperationInformation;
	UIScreenText* _badOperation;
	bool _isLock;

	// ロック画像
	const Vector2 _LOCK_IMAGE_POS = Vector2(0, 0);
	// 情報フレーム画像
	const Vector2 _INFORMATION_FRAME_POS = Vector2(0, 0);
	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(0, 1.0f);
	// エンティティ画像
	const Vector2 _ENTITY_IMAGE_POS = Vector2(0, 0.5f);
	// エンティティの名前
	const Vector2 _NAME_POS = Vector2(0, 0);
	// エンティティのID
	const Vector2 _ID_POS = Vector2(-0.5f, -0.1f);
	// 危険度
	const Vector2 _HAZARD_LEVEL_POS = Vector2(0.7f, -0.1f);
	// 属性情報
	const Vector2 _TYPE_INFORMATION_POS = Vector2(-0.5f, -0.1f);
	// 属性
	const Vector2 _TYPE_POS = Vector2(-0.5f, -0.3f);
	// エネルギー情報
	const Vector2 _ENERGY_INFORMATION_POS = Vector2(0.5f, -0.1f);
	// エネルギー
	const Vector2 _ENERGY_POS = Vector2(0.5f, 0.3f);
	// 作業情報
	const Vector2 _OPERATION_INFORMATION_POS = Vector2(0, -0.6f);
	// 良好な作業状態
	const Vector2 _GOOD_OPERATION_INFORMATION_POS = Vector2(-0.6f, -0.7f);
	// 良好な作業状態のテキスト
	const Vector2 _GOOD_OPERATION_POS = Vector2(-0.6f, 0.7f);
	// 通常の作業状態
	const Vector2 _NORMAL_OPERATION_INFORMATION_POS = Vector2(-0.6f, -0.8f);
	// 通常の作業状態のテキスト
	const Vector2 _NORMAL_OPERATION_POS = Vector2(0, 0.7f);
	// 悪い作業状態
	const Vector2 _BAD_OPERATION_INFORMATION_POS = Vector2(-0.6f, -0.9f);
	// 悪い作業状態のテキスト
	const Vector2 _BAD_OPERATION_POS = Vector2(0.5f, 0.7f);
};

