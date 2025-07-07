#pragma once
#include <vector>
#include "BaseUIScreen.h"

class EntityManagementTipsUI;
class UIScreenImage;
class UIScreenText;

class EntityManagementUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityManagementUI";
	}

	EntityManagementUI(){}
	EntityManagementUI(Transform setTransform, LayerSetting layerSetting, int tipsCount);
	~EntityManagementUI(){}

	void Draw() override;
	/// <summary>
	/// 管理方法の設定
	/// </summary>
	/// <param name="tipsText"></param>
	/// <param name="isLock"></param>
	void SetManagement(std::vector<std::string> tipsText, std::vector<bool> isLock);
	void SetFontSize(int mainSize, int subSize);

private:
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	std::vector<EntityManagementTipsUI*> _tipsUIList;

	const Vector2 _INFORMATION_TEXT_POS = Vector2(-0.1f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 管理方法";
	const Vector2 _DEFAULT_TIPS_POS = Vector2(0, -0.7f);
	const Vector2 _TIPS_SCALE = Vector2(0.95f, 0.15f);
	const float _TIPS_MARGIN = 0.05f;
};

