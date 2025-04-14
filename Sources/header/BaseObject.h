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
	/// ������
	/// </summary>
	virtual void Init(){};
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Proc(){};
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw(){};
	/// <summary>
	/// �j��
	/// </summary>
	virtual void Teardown();

	inline void SetLayer(Layer setLayer) { layer = setLayer;}
	inline Layer GetLayer() { return layer; }
protected:
	// ���C���[
	Layer layer;
	// �`��p�̃n���h��
	int drawHandle;
	// ���W
	Vector2 position;
};