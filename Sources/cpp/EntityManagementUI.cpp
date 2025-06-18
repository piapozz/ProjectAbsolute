#include "../header/EntityManagementUI.h"
#include "../header/EntityManagementTipsUI.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"

EntityManagementUI::EntityManagementUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText("エンティティ 管理方法");
}

void EntityManagementUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	// 管理方法を上から順に表示
	/*for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->Draw();
	}*/
}

void EntityManagementUI::SetActive(bool active)
{
	/*for (int i = 0, max = _tipsUIList.size(); i < max; i++)
	{
		_tipsUIList[i]->SetActive(active);
	}*/
}