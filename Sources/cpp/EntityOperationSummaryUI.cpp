#include "../header/ObjectFactory.h"
#include "../header/EntityOperationSummaryUI.h"
#include "../header/UIScreen.h"

EntityOperationSummaryUI::EntityOperationSummaryUI(Transform setTransform, LayerSetting layerSetting, std::string name, int probability[(int)Level::MAX])
{
	BaseUIScreen::Init(setTransform, layerSetting);

	_isLock = false;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// 背景
	worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	// ロック
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2().one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_OPERATION_LOCK_TEXT);
	// タグ
	worldTransform = Transform(_INFORMATION_POS, Vector2().one(), this);
	_information = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	// 各レベルと成功確率
	int levelMax = (int)Level::MAX;
	_typeLevel.reserve(levelMax);
	_successProbability.reserve(levelMax);
	for (int i = 0; i < levelMax; i++)
	{
		// レベル
		worldTransform = Transform(_OPERATION_LEVEL_POS[i], Vector2().one(), this);
		UIScreenText* typeLevel = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
		_typeLevel.push_back(typeLevel);
		Level level = (Level)i;
		_typeLevel[i]->SetText(ToRomanNumber(level));
		// 成功確率
		worldTransform = Transform(_SUCCESS_PROBABILITY_POS[i], Vector2().one(), this);
		UIScreenText* successProbability = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
		_successProbability.push_back(successProbability);
	}
	// 作業テキストの設定
	SetOperationText(name, probability);
}

/// <summary>
/// 作業テキストの設定
/// </summary>
/// <param name="name"></param>
/// <param name="probability"></param>
void EntityOperationSummaryUI::SetOperationText(std::string name, int probability[(int)Level::MAX])
{
	_information->SetText(name);
	for (int i = 0; i < (int)Level::MAX; i++)
	{
		_successProbability[i]->SetText(std::to_string(probability[i]));
	}
}

void EntityOperationSummaryUI::Draw()
{
	// 基礎
	_BGImage->Draw();
	_information->Draw();
	// ロック
	if (_isLock)
	{
		_lockText->Draw();
	}
	// 詳細
	else
	{
		int levelMax = (int)Level::MAX;
		for (int i = 0; i < levelMax; i++)
		{
			_typeLevel[i]->Draw();
			_successProbability[i]->Draw();
		}
	}
}