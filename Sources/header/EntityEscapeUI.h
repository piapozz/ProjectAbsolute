#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntityEscapeUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityEscapeUI";
	}

	EntityEscapeUI(){}
	EntityEscapeUI(Transform setTransform, LayerSetting layerSetting, float defence[(int)Type::MAX]);
	~EntityEscapeUI(){}

	void Draw();
	void SetEscape(int setMeltdownCount, std::string setDefence[(int)Type::MAX]);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void SetFontSize(int mainSize, int subSize);

private:
	UIScreenImage* _BGImage;
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _informationText;
	UIScreenImage* _meltdownImage;
	UIScreenText* _meltdownInformation;
	UIScreenText* _meltdownCountText;
	UIScreenImage* _defenceImage;
	UIScreenText* _defenceInformation;
	UIScreenText* _defenceText[(int)Type::MAX];
	bool _isLock;

	// 基礎
	const Vector2 _INFORMATION_POS = Vector2(-0.1f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 脱走情報";
	// ロック
	const Vector2 _LOCK_IMAGE_POS = Vector2(0.0f, 0.1f);
	const Vector2 _LOCK_IMAGE_SCALE = Vector2(0.95f, 0.8f);
	const Vector2 _LOCK_TEXT_POS = Vector2(-0.6f, 0.0f);
	const std::string _LOCK_TEXT = "収容違反発生で解除";
	// メルトカウント
	const Vector2 _MELTDOWN_IMAGE_POS = Vector2(-0.65f, 0.05f);
	const Vector2 _MELTDOWN_IMAGE_SCALE = Vector2(0.3f, 0.8f);
	const Vector2 _MELTDOWN_INFORMATION_POS = Vector2(-0.9f, -0.7f);
	const std::string _MELTDOWN_INFORMATION = "メルトカウント";
	const Vector2 _MELTDOWN_COUNT_POS = Vector2(-0.7f, -0.1f);
	const int _MELTDOWN_COUNT_FONT_SIZE = 80;
	// 防御
	const Vector2 _DEFENCE_IMAGE_POS = Vector2(0.3f, 0.05f);
	const Vector2 _DEFENCE_IMAGE_SCALE = Vector2(0.6f, 0.8f);
	const Vector2 _DEFENCE_INFORMATION_POS = Vector2(0.15f, -0.7f);
	const std::string _DEFENCE_INFORMATION = "防御耐性";
	const Vector2 _DEFENCE_TEXT_POS[(int)Type::MAX] =
	{
		Vector2(0.0f, -0.3f),
		Vector2(0.4f, -0.3f),
		Vector2(0.0f, 0.4f),
		Vector2(0.4f, 0.4f)
	};
	const int _DEFENCE_FONT_SIZE = 50;
};

