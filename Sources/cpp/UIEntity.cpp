#include "../header/UIScreen.h"
#include "../header/UIEntity.h"
#include "../header/EntityInformationUI.h"
#include "../header/EntityOperationUI.h"
#include "../header/EntityManagementUI.h"
#include "../header/EntityEscapeUI.h"
#include "../header/EntityWeaponUI.h"
#include "../header/EntitySuitUI.h"
#include "../header/ObjectFactory.h"

UIEntity::UIEntity()
{
	Init();
}

void UIEntity::Init()
{
	BaseUIScreen::Init(_TRANSFORM, _DEFAULT_LAYER);
	ObjectFactory& factory = ObjectFactory::Instance();
	Vector2 position = transform.position;
	Vector2 scale = transform.scale;
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);
	
	// 基礎
	worldTransform = Transform(Vector2().zero(), _BG_SCALE, this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	_BGImage->SetColor(COLOR_BLACK);
	_BGImage->SetOnCursorColor(COLOR_ORANGE);
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2().one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// 基本情報
	worldTransform = Transform(_INFORMATION_POS, _INFORMATION_SCALE, this);
	_entityInformation = factory.CreateWithArgs<EntityInformationUI>(worldTransform, layer);
	_entityInformation->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
	// 作業好感度
	worldTransform = Transform(_OPERATION_POS, _OPERATION_SCALE, this);
	_entityOperation = factory.CreateWithArgs<EntityOperationUI>(worldTransform, layer);
	// 管理方法
	worldTransform = Transform(_MANAGEMENT_POS, _MANAGEMENT_SCALE, this);
	_entityManagement = factory.CreateWithArgs<EntityManagementUI>(worldTransform, layer, 2);
	// 脱走情報
	float defence[(int)Type::MAX] = {0.7f, 1.2f, 0.3f, 1.5f};
	worldTransform = Transform(_ESCAPE_POS, _ESCAPE_SCALE, this);
	_entityEscape = factory.CreateWithArgs<EntityEscapeUI>(worldTransform, layer, defence);
	// 武器防具情報
	worldTransform = Transform(_WEAPON_POS, _WEAPON_SCALE, this);
	_entityWeapon = factory.CreateWithArgs<EntityWeaponUI>(worldTransform, layer);
	worldTransform = Transform(_SUIT_POS, _SUIT_SCALE, this);
	_entitySuit = factory.CreateWithArgs<EntitySuitUI>(worldTransform, layer);
	// 作業回数
	worldTransform = Transform(_OPERATION_COUNT_TEXT_POS, Vector2().one(), this);
	_operationCountText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_operationCountText->SetText(_OPERATION_COUNT_TEXT + '0');
	// 戻るボタン
	worldTransform = Transform(_EXIT_BUTTON_POS, _EXIT_BUTTON_SCALE, this);
	layer = LayerSetting(false, true, Layer::FRONT);
	_exitButton = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
	_exitButton->SetCallback([this]() { this->SetActive(false); });
	_exitButton->SetText(_EXIT_BUTTON_TEXT);

	SetFontSize();
	SetEntityData(-1);
}

void UIEntity::SetFontSize()
{
	_informationText->SetFontSize(_INFORMATION_FONT_SIZE);
	_entityOperation->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
	_entityManagement->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
	_entityEscape->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
	_entityWeapon->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
	_entitySuit->SetFontSize(_MAIN_ITEM_FONT_SIZE, _SUB_ITEM_FONT_SIZE);
}

void UIEntity::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	_entityInformation->Draw();
	_entityOperation->Draw();
	_entityManagement->Draw();
	_entityEscape->Draw();
	_entityWeapon->Draw();
	_entitySuit->Draw();
	_operationCountText->Draw();
	_exitButton->Draw();
}

void UIEntity::SetEntityData(int setID)
{
	// 今後マスターデータからID参照する
	// 基本情報
	int goodOperation[2] = {7, 10};
	int normalOperation[2] = {4, 6};
	int badOperation[2] = {0, 3};
	_entityInformation->SetInformation("Triangle", "E000", Level::I, Type::RED, 10, 
		goodOperation, normalOperation, badOperation, false);
	// 作業好感度
	int operation[4][5] =
	{
		{10, 15, 20, 25, 30},
		{10, 15, 20, 25, 30},
		{10, 15, 20, 25, 30},
		{10, 15, 20, 25, 30},
	};
	_entityOperation->SetOperation(operation);
	// 管理方法
	std::vector<std::string> tips;
	tips.push_back("たった一つの罪と何百もの善は、\n作業の結果が良い場合、\n作業を行った職員の精神力を回復させた。\n当時作業を行っていた職員＜Name＞は\n「精神が清められる気分」だと証言していた。");
	tips.push_back("たった一つの罪と何百もの善の作業で、\nすべてのE-BoxをPE-Boxで生産すると、\nたった一つの罪と何百もの善がいる部門の\n職員全員の精神力が回復した。");
	std::vector<bool> lock;
	lock.push_back(false);
	lock.push_back(false);
	_entityManagement->SetManagement(tips, lock);
	// 脱走情報
	float defence[4] = {1.0f, 1.2f, 0.8f, 1.5f};
	std::string defenceText[4];
	for (int i = 0; i < static_cast<int>(Type::MAX); ++i)
	{
		defenceText[i] = SetPrecision(defence[i]);
	}
	_entityEscape->SetEscape(3, defenceText);
	// 武器情報
	_entityWeapon->SetWeapon(Level::I, "懺悔", Type::RED, 5, 1, 1);
	// 防具情報
	float suitDefence[4] = {0.8f, 0.8f, 0.8f, 1.5f};
	_entitySuit->SetSuit(Level::I, "懺悔", suitDefence);
}

void UIEntity::SetActive(bool setActive)
{
	active = setActive;
	_BGImage->SetInteract(setActive);
	_exitButton->SetActive(setActive);
}