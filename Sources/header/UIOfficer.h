#pragma once
#include "UIOfficerParam.h"
#include "UIWeapon.h"
#include "UISuit.h"
#include "BaseOfficer.h"
#include "Const.h"

class UIOfficer : public BaseUIScreen
{
public:
	UIOfficer();
	~UIOfficer();

	void SetOfficer(BaseOfficer officer);
private:
	// 背景
	UIScreenImage* _pBackground;
	// 名前
	UIScreenImage* _pOfficerName;
	// 画像
	UIScreenImage* _pOfficerImage;
	// 武器
	UIWeapon* _pWeapon;
	// 防具
	UISuit* _pSuit;
	// パラメーター
	UIOfficerParam* _pOfficerParam[(int)Type::MAX];

	// 座標,サイズ(相対)
	
	// 背景
	//const Vector2 BACKGROUND_SIZE = Vector2(0, 0);
	//const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	//// 名前
	//const Vector2 NAME_SIZE = Vector2(0, -);
	//const Vector2 NAME_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// 画像
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// 武器
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// 防具
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// パラメーター
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);

};

