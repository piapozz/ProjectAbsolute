#pragma once
#include "../header/BaseUIScreen.h"

/*
* ishihara
* UIスクリーンテキスト
*/
class UIScreenText : public BaseUIScreen
{
public:
	UIScreenText() {
	}
	UIScreenText(Vector2 setPosition, Vector2 setSize) {
		Init(setPosition, setSize);
	}
	UIScreenText(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIScreenText(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIScreenText(const UIScreenText& obj)
		: BaseUIScreen(obj) {
	}
	~UIScreenText() {
	}
	void Init(Vector2 setPosition, Vector2 setSize);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	static std::string StaticTypeName() {
		return "UIScreenText";
	}

private:
};
