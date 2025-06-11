#pragma once
#include "BaseObject.h"

class EntityInformationUI;
class EntityManagementUI;
class EntityManagementTipsUI;
class EntityEscapeUI;
class EntityWeaponUI;
class EntitySuitUI;
class UIScreenImage;
class UIScreenText;

class UIEntity: public BaseObject
{
public:
	UIEntity();
	~UIEntity(){}

	void SetActive(bool active);
private:
	
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	EntityInformationUI* _entityInformation;
	EntityManagementUI* _entityManagement;
	EntityManagementTipsUI* _entityManagementTips;
	EntityEscapeUI* _entityEscape;
	EntityWeaponUI* _entityWeapon;
	EntitySuitUI* _entitySuit;
};

