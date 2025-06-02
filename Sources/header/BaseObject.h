#pragma once
#include "../header/CommonModule.h"
#include "../header/Const.h"
/*
* Ishihara
* �I�u�W�F�N�g�̊��
*/
class BaseObject
{
public:
	BaseObject(){
		objectType = ObjectType::INVALID;
	 }
	BaseObject(Layer setLayer)
		: layer(setLayer){}
	BaseObject(Layer setLayer, int setDrawHandle)
		: layer(setLayer),drawHandle(setDrawHandle){}
	BaseObject(const BaseObject& obj)
		: layer(obj.layer),drawHandle(obj.drawHandle){}
	~BaseObject(){ }

	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Proc(){};
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw(){
	};
	/// <summary>
	/// �j��
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent(){
	};

	inline void SetLayer(Layer setLayer) { layer = setLayer; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	/// <summary>
	/// �I�u�W�F�N�g���d�Ȃ��Ă��邩�ǂ���
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool IsSamePos(Vector2 pos);
	/// <summary>
	/// �I�u�W�F�N�g���͈͓����ǂ���
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="size"></param>
	/// <returns></returns>
	bool IsSameRect(Vector2 pos, Vector2 size);
	/// <summary>
	/// �\���̐؂�ւ�
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
protected:
	// ���C���[
	Layer layer;
	// �`��p�̃n���h��
	int drawHandle;
	// ���W
	Vector2 position;
	// �ǂ̃^�C�v��
	ObjectType objectType;
	// �T�C�Y
	Vector2 objectSize;
};