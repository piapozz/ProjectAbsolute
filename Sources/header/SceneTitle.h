#pragma once
#include "BaseScene.h"

class SceneTitle :
    public BaseScene
{
private:

    float TITLE_LOGO_X = 600;
    float TITLE_LOGO_Y = 600;

    int _titleLogoHandle = LoadGraph("Resources/Signal_Logo");

    const int TITLE_SELECT_NUMBER = 3;

    float alpha = 255;                  // アルファ値
    float flickerSpeed = 0.05f;         // 点滅の変化速度
    float baseFrequency = 5.0f;         // 基本の点滅周期
    float randomFrequencyOffset = 1.0f; // 周期のランダムな範囲


    int startTime;

public:

    SceneTitle();
    ~SceneTitle();

    void Init();
    void Proc();
    void Draw();
    int CheckChangeScene();
};

