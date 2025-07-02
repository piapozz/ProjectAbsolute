#include "../header/PhaseStandby.h"
#include "../header/UIOfficer.h"
#include "../header/ObjectFactory.h"

void PhaseStandby::Init()
{
	// 入力受付クラスを生成
	// キャラの詳細UI(入力なし)
	UIOfficer* uiOfficer = ObjectFactory::Instance().CreateWithArgs<UIOfficer>();
	// 所持金UI(入力なし)
	// 区画に生成するキャラクターUI
	// 控えキャラクターUI
	// 開始ボタン
	UIScreenButton* startButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>();
}