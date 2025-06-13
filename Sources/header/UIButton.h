#pragma once
#include "UIText.h"
#include "UIImage.h"
#include <functional>
/*
* Ishihara
* UIボタン
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
	/// コールバックの設定
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {_callback = callback;}
private:
	// テキスト
	UIText* _pText;
	// 画像
	UIImage* _pImage; 
	// コールバック
	std::function<void()> _callback;
};

