#include "../header/EntityOperationUI.h"
#include "../header/EntityOperationSummaryUI.h"
#include "../header/ObjectFactory.h"

EntityOperationUI::EntityOperationUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	int typeMax = (int)Type::MAX;
	_summaryUIList.reserve(typeMax);
	for (int i = 0; i < typeMax; i++)
	{
		worldTransform = Transform(_OPERATION_POS[i], _OPERATION_SIZE, this);
		int porobability[(int)Level::MAX] = {50, 60, 70, 80, 90};
		EntityOperationSummaryUI* summary = 
			factory.CreateWithArgs<EntityOperationSummaryUI>(worldTransform, layer, ToOperation((Type)i), porobability);
		_summaryUIList.push_back(summary);
	}

	// ˜g
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_informationBGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_informationBGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	_information = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_information->SetText(_INFORMATION_TEXT);
}

void EntityOperationUI::SetFontSize(int mainSize, int subSize)
{
	_information->SetFontSize(mainSize);
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_summaryUIList[i]->SetFontSize(subSize);
	}
}

void EntityOperationUI::Draw()
{
	_informationBGImage->Draw();
	_information->Draw();

	for (int i = 0; i < (int)Type::MAX; i++)
	{
		_summaryUIList[i]->Draw();
	}
}

void EntityOperationUI::SetOperation(int setProbability[(int)Type::MAX][(int)Level::MAX])
{
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		int porobability[(int)Level::MAX] = {50, 60, 70, 80, 90};
		_summaryUIList[i]->SetProbability(setProbability[i]);
	}
}