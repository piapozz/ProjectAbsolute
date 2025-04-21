#pragma once
#include "BaseObject.h"
/*
* Ishihara
* UI���
*/
class BaseUI: public BaseObject
{
public:
	BaseUI() {}
	BaseUI(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseUI(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseUI(const BaseUI& obj)
		: BaseObject(obj) {}
	~BaseUI() {}

	/// <summary>
	/// ������
	/// </summary>
	virtual void Init(Vector2 setPosition, Vector2 setSize);
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
	/// �\���̐؂�ւ�
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
	/// <summary>
	/// ��ʂɒǏ]�����邩�ǂ���
	/// </summary>
	/// <param name="is2D"></param>
	void Set2D(bool is2D) { _is2D = is2D; }
protected:
	int fontHandle;
	int textGraph;;
private:
	// "2D��3D��
	bool _is2D;
};

