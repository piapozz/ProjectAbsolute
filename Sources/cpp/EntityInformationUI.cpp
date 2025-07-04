#include "../header/ObjectFactory.h"
#include "../header/EntityInformationUI.h"
#include "../header/UIScreen.h"
#include "../header/UIText.h"

EntityInformationUI::EntityInformationUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_isLock = false;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// òg
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_informationBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_informationBGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	_information = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_information->SetText(_INFORMATION_TEXT);
	// ÉçÉbÉN
	worldTransform = Transform(_LOCK_IMAGE_POS, _LOCK_IMAGE_SCALE, this);
	_lockImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2::one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_LOCK_TEXT);
	// âÊëú
	worldTransform = Transform(_ENTITY_IMAGE_POS, _ENTITY_IMAGE_SCALE, this);
	_image = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	// ëÆê´
	worldTransform = Transform(_TYPE_BG_POS, _TYPE_BG_SCALE, this);
	_typeBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_TYPE_INFORMATION_POS, Vector2::one(), this);
	_typeInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_typeInformation->SetText(_TYPE_INFORMATION_TEXT);
	worldTransform = Transform(_TYPE_POS, Vector2::one(), this);
	_type = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_type->SetText("X");
	// ÉGÉlÉãÉMÅ[
	worldTransform = Transform(_ENERGY_BG_POS, _ENERGY_BG_SCALE, this);
	_energyBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_ENERGY_INFORMATION_POS, Vector2::one(), this);
	_energyInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_energyInformation->SetText(_ENERGY_INFORMATION_TEXT);
	worldTransform = Transform(_ENERGY_POS, Vector2::one(), this);
	_energy = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_energy->SetText("X");
	// äÓëbèÓïÒ
	worldTransform = Transform(_NAME_POS, Vector2().one(), this);
	_name = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_name->SetText("XXXX");
	worldTransform = Transform(_ID_POS, Vector2().one(), this);
	_id = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_id->SetText("E-XXX");
	worldTransform = Transform(_HAZARD_LEVEL_POS, Vector2().one(), this);
	_hazardLevel = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_hazardLevel->SetText("XXXX");
	// çÏã∆èÓïÒ
	worldTransform = Transform(_OPERATION_BG_POS, _OPARATION_BG_SCALE, this);
	_operationBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_OPERATION_INFORMATION_POS, Vector2().one(), this);
	_operationInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_operationInformation->SetText(_OPERATION_INFORMATION_TEXT);
	worldTransform = Transform(_GOOD_OPERATION_INFORMATION_POS, Vector2().one(), this);
	_goodOperationInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_goodOperationInformation->SetText(_GOOD_OPERATION_INFORMATION_TEXT);
	worldTransform = Transform(_NORMAL_OPERATION_INFORMATION_POS, Vector2().one(), this);
	_normalOperationInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_normalOperationInformation->SetText(_NORMAL_OPERATION_INFORMATION_TEXT);
	worldTransform = Transform(_BAD_OPERATION_INFORMATION_POS, Vector2().one(), this);
	_badOperationInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_badOperationInformation->SetText(_BAD_OPERATION_INFORMATION_TEXT);
	worldTransform = Transform(_GOOD_OPERATION_POS, Vector2().one(), this);
	_goodOperation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_goodOperation->SetText("8 - 10");
	worldTransform = Transform(_NORMAL_OPERATION_POS, Vector2().one(), this);
	_normalOperation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_normalOperation->SetText("4 - 7");
	worldTransform = Transform(_BAD_OPERATION_POS, Vector2().one(), this);
	_badOperation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_badOperation->SetText("0 - 3");
}

void EntityInformationUI::Draw()
{
	_informationBGImage->Draw();
	_information->Draw();
	if (_isLock)
	{
		_lockImage->Draw();
		_lockText->Draw();
	}
	else
	{
		_image->Draw();
		_typeBGImage->Draw();
		_typeInformation->Draw();
		_type->Draw();
		_energyBGImage->Draw();
		_energyInformation->Draw();
		_energy->Draw();
		_name->Draw();
		_id->Draw();
		_hazardLevel->Draw();
		_operationBGImage->Draw();
		_operationInformation->Draw();
		_goodOperationInformation->Draw();
		_normalOperationInformation->Draw();
		_badOperationInformation->Draw();
		_goodOperation->Draw();
		_normalOperation->Draw();
		_badOperation->Draw();
	}
}

void EntityInformationUI::SetInformation(std::string setName, std::string setID, Level setLevel, Type setType,
		int setEnergy, int setGoodOperation[2], int setNormalOperation[2], int setBadOperation[2], bool isLock)
{
	_name->SetText(setName);
	_id->SetText(setID);
	_hazardLevel->SetText(ToRomanNumber(setLevel));
	_type->SetText(ToString(setType));
	_type->SetTextColor(ToColor(setType));
	_energy->SetText(std::to_string(setEnergy));
	_goodOperation->SetText(std::to_string(setGoodOperation[0]) + " - " + std::to_string(setGoodOperation[1]));
	_normalOperation->SetText(std::to_string(setNormalOperation[0]) + " - " + std::to_string(setNormalOperation[1]));
	_badOperation->SetText(std::to_string(setBadOperation[0]) + " - " + std::to_string(setBadOperation[1]));
	_isLock = isLock;
}
