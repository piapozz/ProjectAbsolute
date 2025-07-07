#pragma once
#include <vector>
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
	EntityOperationSummaryUI(Transform setTransform, LayerSetting layerSetting, std::string name, int probability[(int)Level::MAX]);
	~EntityOperationSummaryUI(){}

	void Draw() override;
	/// <summary>
	/// 作業名の設定
	/// </summary>
	/// <param name="name"></param>
	void SetOperationName(std::string name);
	/// <summary>
	/// 確率の設定
	/// </summary>
	/// <param name="probability"></param>
	void SetProbability(int probability[(int)Level::MAX]);
	void SetFontSize(int setSize);

private:
	UIScreenImage* _BGImage;
	UIScreenText* _lockText;
	UIScreenText* _information;
	std::vector<UIScreenText*> _typeLevel;
	std::vector<UIScreenText*> _successProbability;
	bool _isLock;

	// 情報テキスト
	const Vector2 _INFORMATION_POS = Vector2(-0.15f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 基本情報";
	// ロックテキスト
	const Vector2 _LOCK_TEXT_POS = Vector2(-0.45f, 0.0f);
	const std::string _OPERATION_LOCK_TEXT = "作業で解除";
	// 作業
	const Vector2 _OPERATION_LEVEL_POS[(int)Level::MAX] =
	{
		Vector2(-0.5f, -0.55f),
		Vector2(-0.5f, -0.25f),
		Vector2(-0.5f, 0.05f),
		Vector2(-0.5f, 0.35f),
		Vector2(-0.5f, 0.65f),
	};
	// 成功率
	const Vector2 _SUCCESS_PROBABILITY_POS[(int)Level::MAX] =
	{
		Vector2(0.5f, -0.55f),
		Vector2(0.5f, -0.25f),
		Vector2(0.5f, 0.05f),
		Vector2(0.5f, 0.35f),
		Vector2(0.5f, 0.65f),
	};
};

