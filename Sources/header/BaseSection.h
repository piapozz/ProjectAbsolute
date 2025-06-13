#pragma once
#include "BaseObject.h"

class BaseCharacter;
/*
* Ishihara
* �����̊��
*/
class BaseSection: public BaseObject
{
public:
	BaseSection(): BaseObject() { }
	BaseSection(Transform setTransform, LayerSetting layerSetting){
		Init(setTransform, layerSetting);
	}
	BaseSection(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseSection(Layer setLayer, int setDrawHandle)
		: BaseObject(setLayer, setDrawHandle) {}
	BaseSection(const BaseSection& obj)
		: BaseObject(obj) {}
	~BaseSection() {}

	/// <summary>
	/// ������
	/// </summary>
 	virtual void Init(Transform setTransform, LayerSetting layerSetting);
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	void Proc() override;
	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown() override;
	/// <summary>
	/// �N���b�N�����Ƃ��̃C�x���g
	/// </summary>
	void ClickEvent() override;
	/// <summary>
	/// �L�����N�^�[�̎擾
	/// </summary>
	/// <returns></returns>
	std::vector<BaseCharacter*> GetCharacters();
protected:
	// �������ǂ̕����̃^�C�v��
	SectionType sectionType;
	// �ڑ���
	bool isConnect[static_cast<int>(DirFour::MAX)];
};

