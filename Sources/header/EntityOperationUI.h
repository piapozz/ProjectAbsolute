#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"
#include <vector>
class EntityOperationSummaryUI;

class EntityOperationUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityOperationUI";
	}

	EntityOperationUI(){}
	EntityOperationUI(Transform setTransform, LayerSetting layerSetting);
	~EntityOperationUI(){}

	void Draw() override;

private:
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _information;
	UIScreenImage* _informationBGImage;
	std::vector<EntityOperationSummaryUI*> _summaryUIList;

	// 情報フレーム画像
	const Vector2 _INFORMATION_FRAME_POS = Vector2(0, 0);
	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(0, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 基本情報";
};

