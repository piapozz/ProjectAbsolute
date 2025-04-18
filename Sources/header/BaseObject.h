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
	BaseObject(){}
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
	virtual void Proc() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// �j��
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent() = 0;

	inline void SetLayer(Layer setLayer) { layer = setLayer; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	inline bool IsSamePos(Vector2 pos);
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