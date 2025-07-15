#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntitySuitUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntitySuitUI";
	}

	EntitySuitUI(){
	}
	EntitySuitUI(Transform setTransform, LayerSetting layerSetting);
	~EntitySuitUI(){
	}

	void Draw();
	void SetSuit(Level setLevel, std::string setName, float setDefence[(int)Type::MAX]);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void SetFontSize(int mainSize, int subSize);

private:
	UIScreenImage* _BGImage;
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _informationText;
	UIScreenImage* _image;
	UIScreenText* _rank;
	UIScreenText* _name;
	UIScreenText* _typeDefenceInformation[(int)Type::MAX];
	UIScreenText* _typeDefence[(int)Type::MAX];
	bool _isLock;

	const Vector2 _INFORMATION_TEXT_POS = Vector2(0.0f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 防具";
	const Vector2 _LOCK_TEXT_POS = Vector2(0.0f, 0.0f);
	const std::string _LOCK_TEXT = "規定作業回数で解除";
	const Vector2 _LOCK_IMAGE_POS = Vector2(0.0f, 0.05f);
	const Vector2 _LOCK_IMAGE_SCALE = Vector2(0.95f, 0.9f);
	const Vector2 _IMAGE_POS = Vector2(0.0f, -0.5f);
	const Vector2 _IMAGE_SCALE = Vector2(0.95f, 0.3f);
	const Vector2 _RANK_TEXT_POS = Vector2(0.0f, -0.05f);
	const Vector2 _NAME_TEXT_POS = Vector2(0.0f, 0.1f);
	const std::string _GOOD_DEFENCE = "耐性";
	const std::string _NORMAL_DEFENCE = "普通";
	const std::string _BAD_DEFENCE = "脆弱";
	const Vector2 _DEFENCE_INFORMATION_TEXT_POS[(int)Type::MAX] =
	{
		Vector2(-0.5f, 0.25f),
		Vector2(-0.5f, 0.4f),
		Vector2(-0.5f, 0.55f),
		Vector2(-0.5f, 0.7f)
	};
	const Vector2 _DEFENCE_TEXT_POS[(int)Type::MAX] =
	{
		Vector2(0.5f, 0.25f),
		Vector2(0.5f, 0.4f),
		Vector2(0.5f, 0.55f),
		Vector2(0.5f, 0.7f)
	};
};

