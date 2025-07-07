#include "../header/PhaseStandby.h"
#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"
#include "../header/UIOfficerList.h"

void PhaseStandby::Init()
{
	// 入力受付クラスを生成
	// キャラの詳細UI(入力なし)
	Transform trans = Transform(OFFICCER_UI_POS, OFFICCER_UI_SIZE);
	LayerSetting layer = {false , false , Layer::MIDDLE};
	UIOfficer* uiOfficer = ObjectFactory::Instance().CreateWithArgs<UIOfficer>(trans, true, layer);
	// 所持金UI(入力なし)
	 UIScreenText* uiMoney = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(MONEY_POS, MONEY_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	 uiMoney->SetText("所持金: 1000G");
	// 区画に生成するキャラクターUI
	trans = Transform(DIVISION_POS, DIVISION_SIZE);
	layer = {true, false, Layer::BACK};
	UIOfficerList* uiDIVISIONList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 控えキャラクターUI
	trans = Transform(OFFICERLIST_POS, OFFICERLIST_SIZE);
	layer = {true, false, Layer::BACK};
	UIOfficerList* uiOfficerList = ObjectFactory::Instance().CreateWithArgs<UIOfficerList>(trans, layer);
	// 開始ボタン
	trans = Transform(START_POS, START_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* startButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	startButton->SetText("Start");
	startButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::MAIN);
	});
	// 雇用ボタン
	trans = Transform(HIRE_POS, HIRE_SIZE);
	layer = {true, true, Layer::BACK};
	UIScreenButton* hireButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	hireButton->SetText("雇用");
	hireButton->SetCallback([this]() {
		this->ChangePhase(PhaseName::MAIN);
	});
}