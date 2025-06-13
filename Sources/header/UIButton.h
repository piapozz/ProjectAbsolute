#pragma once
#include "UIText.h"
#include "UIImage.h"
#include <functional>
/*
* Ishihara
* UI�{�^��
*/
class UIButton: public BaseUI
{
public:
	UIButton() {}
	UIButton(Transform setTransform, LayerSetting layerSetting){
		Init(setTransform, layerSetting);
	}
	UIButton(Transform setTransform, std::function<void()> callback, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
		SetCallback(callback);
	}
	UIButton(Layer setLayer)
		: BaseUI(setLayer) {}
	UIButton(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UIButton(const UIButton& obj)
		: BaseUI(obj) {}
	~UIButton() {}
	void Init(Transform setTransform, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override {_callback();}

	static std::string StaticTypeName() {
		return "UIButton";
	}
	void SetText(std::string str) {
		_pText->SetText(str);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

	/// <summary>
	/// �R�[���o�b�N�̐ݒ�
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {_callback = callback;}
private:
	// �e�L�X�g
	UIText* _pText;
	// �摜
	UIImage* _pImage; 
	// �R�[���o�b�N
	std::function<void()> _callback;
};

