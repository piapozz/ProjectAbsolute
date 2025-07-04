#include "../header/EntitySuitUI.h"
#include "../header/ObjectFactory.h"

EntitySuitUI::EntitySuitUI(Transform setTransform, LayerSetting layerSetting)
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
	// 防御
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		worldTransform = Transform(_DEFENCE_INFORMATION_TEXT_POS[i], Vector2::one(), this);
		_typeDefenceInformation[i] = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
		Type type = (Type)i;
		_typeDefenceInformation[i]->SetText(ToString(type));
		_typeDefenceInformation[i]->SetTextColor(ToColor(type));
		worldTransform = Transform(_DEFENCE_TEXT_POS[i], Vector2::one(), this);
		_typeDefence[i] = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
		_typeDefence[i]->SetText("XX");
	}
}

void EntitySuitUI::Draw()
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
		for (int i = 0; i < (int)Type::MAX; i++)
		{
			_typeDefenceInformation[i]->Draw();
			_typeDefence[i]->Draw();
		}
	}
}

void EntitySuitUI::SetSuit(Level setLevel, std::string setName, float setDefence[(int)Type::MAX])
{
	_rank->SetText(ToRomanNumber(setLevel));
	_name->SetText(setName);
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		if (setDefence[i] < 1)
			_typeDefence[i]->SetText(std::to_string(setDefence[i]) + '(' + _GOOD_DEFENCE + ')');
		else if (setDefence[i] > 1)
			_typeDefence[i]->SetText(std::to_string(setDefence[i]) + '(' + _BAD_DEFENCE + ')');
		else
			_typeDefence[i]->SetText(std::to_string(setDefence[i]) + '(' + _NORMAL_DEFENCE + ')');
	}
}