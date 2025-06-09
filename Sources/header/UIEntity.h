#pragma once
#include "BaseObject.h"

class EntityInformationUI;
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
};

