#pragma once
#include "../header/CommonModule.h"
#include "../header/Const.h"
#include "../header/AutoTypeNameObject.h"
/*
* Ishihara
* �I�u�W�F�N�g�̊��
*/
class BaseObject : public AutoTypeNameObject
{
public:
	BaseObject(){
		objectType = ObjectType::INVALID;
	 }
	BaseObject(Vector2 pos, Vector2 size, Layer setLayer)
		: position(pos), objectSize(size), layer(setLayer) {
		objectType = ObjectType::INVALID;
		drawHandle = -1;
	}
	BaseObject(Vector2 pos, Vector2 size, LayerSetting layerSetting)
		: position(pos), objectSize(size), active(layerSetting.m_active), 
		interactable(layerSetting.m_interact), layer(layerSetting.m_layer) {
		objectType = ObjectType::INVALID;
		drawHandle = -1;
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
	virtual void Proc(){}
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw(){}
	/// <summary>
	/// �j��
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent(){}
	virtual void OnCursor(){}
	virtual void NotOnCursor(){}

	static std::string StaticTypeName() {
		return "BaseObject";
	}

	inline Vector2 GetPosition(){ return position; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	inline bool GetActive() { return active; }
	inline bool GetInteract() { return interactable; }
	inline void SetPosition(Vector2 setPosition){ position = setPosition; }
	inline void SetSize(Vector2 setSize){ objectSize = setSize; }
	inline void SetActive(bool setActive){ active = setActive; }
	inline void SetInteract(bool setInteract){ interactable = setInteract; }

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
protected:
	// �A�N�e�B�u���
	bool active;
	// �C���^���N�g�\��
	bool interactable;
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