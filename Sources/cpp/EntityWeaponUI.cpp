#include "../header/EntityWeaponUI.h"
#include "../header/ObjectFactory.h"

EntityWeaponUI::EntityWeaponUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_isLock = false;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// 基礎
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_BGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// ロック
	worldTransform = Transform(_LOCK_IMAGE_POS, _LOCK_IMAGE_SCALE, this);
	_lockImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2::one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_LOCK_TEXT);
	// 画像
	worldTransform = Transform(_IMAGE_POS, _IMAGE_SCALE, this);
	_image = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	// 危険度
	worldTransform = Transform(_RANK_TEXT_POS, Vector2::one(), this);
	_rank = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_rank->SetText("XX");
	// 名前
	worldTransform = Transform(_NAME_TEXT_POS, Vector2::one(), this);
	_name = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_name->SetText("XX");
	// 属性
	worldTransform = Transform(_TYPE_INFORMATION_TEXT_POS, Vector2::one(), this);
	_typeInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_typeInformation->SetText(_TYPE_INFORMATION_TEXT);
	worldTransform = Transform(_TYPE_TEXT_POS, Vector2::one(), this);
	_type = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_type->SetText("XX");
	// ダメージ
	worldTransform = Transform(_DAMAGE_INFORMATION_TEXT_POS, Vector2::one(), this);
	_damageInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_damageInformation->SetText(_DAMAGE_INFORMATION_TEXT);
	worldTransform = Transform(_DAMAGE_TEXT_POS, Vector2::one(), this);
	_damage = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_damage->SetText("XX");
	// 速度
	worldTransform = Transform(_SPEED_INFORMATION_TEXT_POS, Vector2::one(), this);
	_speedInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_speedInformation->SetText(_SPEED_INFORMATION_TEXT);
	worldTransform = Transform(_SPEED_TEXT_POS, Vector2::one(), this);
	_speed = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_speed->SetText("XX");
	// 射程
	worldTransform = Transform(_RANGE_INFORMATION_TEXT_POS, Vector2::one(), this);
	_rangeInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_rangeInformation->SetText(_RANGE_INFORMATION_TEXT);
	worldTransform = Transform(_RANGE_TEXT_POS, Vector2::one(), this);
	_range = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_range->SetText("XX");
}

void EntityWeaponUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	if (_isLock)
	{
		_lockImage->Draw();
		_lockText->Draw();
	}
	else
	{
		_image->Draw();
		_rank->Draw();
		_name->Draw();
		_typeInformation->Draw();
		_type->Draw();
		_damageInformation->Draw();
		_damage->Draw();
		_speedInformation->Draw();
		_speed->Draw();
		_rangeInformation->Draw();
		_range->Draw();
	}
}

void EntityWeaponUI::SetWeapon(Level setLevel, std::string setName, Type setType, int setDamage, int setSpeed, int setRange)
{

}

void EntityWeaponUI::SetFontSize(int mainSize, int subSize)
{
	_informationText->SetFontSize(mainSize);
}