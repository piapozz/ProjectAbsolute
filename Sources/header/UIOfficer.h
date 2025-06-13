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
	// �w�i
	UIScreenImage* _pBackground;
	// ���O
	UIScreenImage* _pOfficerName;
	// �摜
	UIScreenImage* _pOfficerImage;
	// ����
	UIWeapon* _pWeapon;
	// �h��
	UISuit* _pSuit;
	// �p�����[�^�[
	UIOfficerParam* _pOfficerParam[(int)Type::MAX];

	// ���W,�T�C�Y(����)
	
	// �w�i
	//const Vector2 BACKGROUND_SIZE = Vector2(0, 0);
	//const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	//// ���O
	//const Vector2 NAME_SIZE = Vector2(0, -);
	//const Vector2 NAME_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// �摜
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// ����
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// �h��
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//// �p�����[�^�[
	//const Vector2 BACKGROUND_SIZE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	//const Vector2 BACKGROUND_POS =  Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);

};

