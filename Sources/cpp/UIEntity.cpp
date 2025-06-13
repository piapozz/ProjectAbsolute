#include "../header/UIScreen.h"
#include "../header/UIEntity.h"
#include "../header/EntityInformationUI.h"
#include "../header/EntityManagementUI.h"
#include "../header/EntityEscapeUI.h"
#include "../header/EntityWeaponUI.h"
#include "../header/EntitySuitUI.h"

UIEntity::UIEntity()
{

}

void UIEntity::Proc()
{
	_BGImage->Proc();
	_informationText->Proc();
	_entityInformation->Proc();
	_entityManagement->Proc();
	_entityEscape->Proc();
	_entityWeapon->Proc();
	_entitySuit->Proc();
}

void UIEntity::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	_entityInformation->Draw();
	_entityManagement->Draw();
	_entityEscape->Draw();
	_entityWeapon->Draw();
	_entitySuit->Draw();
}

void UIEntity::SetActive(bool active)
{
	// 全EntityUIのアクティブを切り替える
	_BGImage->SetActive(active);
	_informationText->SetActive(active);
	_entityInformation->SetActive(active);
	_entityManagement->SetActive(active);
	_entityEscape->SetActive(active);
	_entityWeapon->SetActive(active);
	_entitySuit->SetActive(active);
}