#pragma once
#include "CommonModule.h"
#include "DxLib.h"
/*
* Ishihara
* �I�u�W�F�N�g�̊��
*/
class BaseObject
{
public:
	BaseObject(){}
	BaseObject(int setLayer) 
		: layer(setLayer){}
	BaseObject(int setLayer, int setDrawHandle) 
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

	inline void SetLayer(int setLayer) { layer = setLayer;}
	inline int GetLayer() { return layer; }
protected:
	// ���C���[
	int layer;
	// �`��p�̃n���h��
	int drawHandle;
	// ���W
	Vector2 position;
};