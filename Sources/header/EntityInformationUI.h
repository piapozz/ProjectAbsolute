#pragma once
#include "BaseObject.h"

class UIScreenImage;
class UIScreenText;

class EntityInformationUI : public BaseObject
{
public:
	EntityInformationUI(){}
	~EntityInformationUI(){}

	void SetActive(bool active);

private:
	UIScreenImage* _lockImage;
	UIScreenImage* _informationFrame;
	UIScreenText* _information;
	UIScreenImage* _image;
	UIScreenText* _name;
	UIScreenText* _id;
	UIScreenText* _hazardLevel;
	UIScreenText* _typeInformation;
	UIScreenText* _type;
	UIScreenText* _energyInformation;
	UIScreenText* _energy;
	UIScreenText* _operationInformation;
	UIScreenText* _goodOperationInformation;
	UIScreenText* _goodOperation;
	UIScreenText* _normalOperationInformation;
	UIScreenText* _normalOperation;
	UIScreenText* _badOperationInformation;
	UIScreenText* _badOperation;
};

