#pragma once
#include "BaseUIScreen.h"

class UIScreenImage;
class UIScreenText;

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
	inline void SetLock(bool isLock){ _isLock = isLock; }

private:
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenImage* _informationBGImage;
	UIScreenText* _information;
	UIScreenImage* _image;
	UIScreenText* _name;
	UIScreenText* _id;
	UIScreenText* _hazardLevel;
	UIScreenImage* _typeBGImage;
	UIScreenText* _typeInformation;
	UIScreenText* _type;
	UIScreenImage* _energyBGImage;
	UIScreenText* _energyInformation;
	UIScreenText* _energy;
	UIScreenText* _operationInformation;
	UIScreenImage* _operationBGImage;
	UIScreenText* _goodOperationInformation;
	UIScreenText* _goodOperation;
	UIScreenText* _normalOperationInformation;
	UIScreenText* _normalOperation;
	UIScreenText* _badOperationInformation;
	UIScreenText* _badOperation;
	bool _isLock;

	// ロック
	const Vector2 _LOCK_IMAGE_POS = Vector2(0, 0.05f);
	const Vector2 _LOCK_IMAGE_SCALE = Vector2(0.95f, 0.9f);
	const Vector2 _LOCK_TEXT_POS = Vector2(-0.15f, 0);
	const std::string _LOCK_TEXT = "基本情報";
	// 情報フレーム画像
	const Vector2 _INFORMATION_FRAME_POS = Vector2(0, 0);
	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(0, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 基本情報";
	// エンティティ画像
	const Vector2 _ENTITY_IMAGE_POS = Vector2(-0.35f, -0.4f);
	const Vector2 _ENTITY_IMAGE_SCALE = Vector2(0.55f, 0.4f);
	// エンティティの名前
	const Vector2 _NAME_POS = Vector2(-0.4f, 0.05f);
	// エンティティのID
	const Vector2 _ID_POS = Vector2(-0.5f, 0.2f);
	// 危険度
	const Vector2 _HAZARD_LEVEL_POS = Vector2(0.2f, 0.2f);
	// 属性
	const Vector2 _TYPE_BG_POS = Vector2(0.6f, -0.6f);
	const Vector2 _TYPE_BG_SCALE = Vector2(0.3f, 0.2f);
	const Vector2 _TYPE_INFORMATION_POS = Vector2(0.3f, -0.8f);
	const Vector2 _TYPE_POS = Vector2(0.6f, -0.6f);
	const std::string _TYPE_INFORMATION_TEXT = "属性";
	// エネルギー情報
	const Vector2 _ENERGY_BG_POS = Vector2(0.6f, -0.1f);
	const Vector2 _ENERGY_BG_SCALE = Vector2(0.3f, 0.2f);
	const Vector2 _ENERGY_INFORMATION_POS = Vector2(0.3f, -0.3f);
	const std::string _ENERGY_INFORMATION_TEXT = "エネルギー";
	const Vector2 _ENERGY_POS = Vector2(0.6f, -0.1f);
	// 作業情報
	const Vector2 _OPERATION_BG_POS = Vector2(0, 0.6f);
	const Vector2 _OPARATION_BG_SCALE = Vector2(0.9f, 0.3f);
	const Vector2 _OPERATION_INFORMATION_POS = Vector2(-0.2f, 0.35f);
	const std::string _OPERATION_INFORMATION_TEXT = "作業結果";
	// 良好な作業状態
	const Vector2 _GOOD_OPERATION_INFORMATION_POS = Vector2(-0.6f, 0.5f);
	const std::string _GOOD_OPERATION_INFORMATION_TEXT = "良い";
	// 良好な作業状態のテキスト
	const Vector2 _GOOD_OPERATION_POS = Vector2(0.2f, 0.5f);
	// 通常の作業状態
	const Vector2 _NORMAL_OPERATION_INFORMATION_POS = Vector2(-0.6f, 0.65f);
	const std::string _NORMAL_OPERATION_INFORMATION_TEXT = "普通";
	// 通常の作業状態のテキスト
	const Vector2 _NORMAL_OPERATION_POS = Vector2(0.2f, 0.65f);
	// 悪い作業状態
	const Vector2 _BAD_OPERATION_INFORMATION_POS = Vector2(-0.6f, 0.8f);
	const std::string _BAD_OPERATION_INFORMATION_TEXT = "悪い";
	// 悪い作業状態のテキスト
	const Vector2 _BAD_OPERATION_POS = Vector2(0.2f, 0.8f);
};

