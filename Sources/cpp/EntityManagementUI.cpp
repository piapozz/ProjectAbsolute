#include "../header/EntityManagementUI.h"
#include "../header/EntityManagementTipsUI.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"

EntityManagementUI::EntityManagementUI(Transform setTransform, LayerSetting layerSetting, int tipsCount)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// Šî‘b
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_BGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// ŠÇ—•û–@
	for (int i = 0; i < tipsCount; i++)
	{
		Vector2 position = Vector2(_DEFAULT_TIPS_POS) + (Vector2(0, _TIPS_SCALE.y * 2 + _TIPS_MARGIN) * i);
		worldTransform = Transform(position, _TIPS_SCALE, this);
		std::string tipsText = "XXXXX";
		EntityManagementTipsUI* tips = factory.CreateWithArgs<EntityManagementTipsUI>(worldTransform, layer, tipsText, i + 1);
		_tipsUIList.push_back(tips);
	}
}

void EntityManagementUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	// ŠÇ—•û–@‚ğã‚©‚ç‡‚É•\¦
	for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->Draw();
	}
}

void EntityManagementUI::SetManagement(std::vector<std::string> tipsText, std::vector<bool> isLock)
{
	for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->SetTipsText(tipsText[i]);
		_tipsUIList[i]->SetLock(isLock[i]);
	}
}