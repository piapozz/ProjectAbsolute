#pragma once
#include "BaseUIScreen.h"
class UIScreenImage;
class UIScreenText;

class EntityOperationSummaryUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityOperationSummaryUI";
	}

	EntityOperationSummaryUI(){}
	EntityOperationSummaryUI(Transform setTransform, LayerSetting layerSetting);
	~EntityOperationSummaryUI(){}

	void Draw() override;

private:
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _information;
	UIScreenImage* _informationBGImage;

	// 情報フレーム画像
	const Vector2 _INFORMATION_FRAME_POS = Vector2(0, 0);
	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(0, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 基本情報";
};

