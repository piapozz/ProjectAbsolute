#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"
#include <vector>
class EntityOperationSummaryUI;

class EntityOperationUI: public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityOperationUI";
	}

	EntityOperationUI(){
	}
	EntityOperationUI(Transform setTransform, LayerSetting layerSetting);
	~EntityOperationUI(){
	}

	void Draw() override;

private:
	UIScreenText* _information;
	UIScreenImage* _informationBGImage;
	std::vector<EntityOperationSummaryUI*> _summaryUIList;

	// 情報フレーム画像
	const Vector2 _INFORMATION_FRAME_POS = Vector2(0, 0);
	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(0, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 作業情報";
	const Vector2 _OPERATION_POS[(int)Type::MAX] =
	{
		Vector2(-0.5f, -0.3f),
		Vector2(0.5f, -0.3f),
		Vector2(-0.5f, 0.55f),
		Vector2(0.5f, 0.55f),
	};
	const Vector2 _OPERATION_SIZE = Vector2(0.45f, 0.4f);
};

