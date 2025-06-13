#pragma once
#include "BaseObject.h"

class UIScreenImage;
class UIScreenText;

class EntityInformationUI : public BaseObject
{
public:
	EntityInformationUI(Transform setTransform, LayerSetting layerSetting);
	~EntityInformationUI(){}

	void Draw();
	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }

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
	bool _isLock;
};

