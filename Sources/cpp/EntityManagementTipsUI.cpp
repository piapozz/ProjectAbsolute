#include "../header/EntityManagementTipsUI.h"

EntityManagementTipsUI::EntityManagementTipsUI(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting, std::string tipsText)
	: BaseObject(setPosition, setSize, layerSetting)
{
	_isLock = true;
	// テキストの設定もする
	_lockText = new UIScreenText();
	_tipsInformation = new UIScreenText();
	_tipsText = new UIScreenText();
}

void EntityManagementTipsUI::Draw()
{
	if (_isLock)
	{
		_lockText->Draw();
	}
	else
	{
		_tipsInformation->Draw();
		_tipsText->Draw();
	}
}

void EntityManagementTipsUI::SetActive(bool active)
{
	if (_isLock)
	{
		_lockText->SetActive(active);
	}
	else
	{
		_tipsInformation->SetActive(active);
		_tipsText->SetActive(active);
	}
}