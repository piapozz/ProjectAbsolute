#pragma once
#include <vector>
#include <string>
#include "DxLib.h"

// 四方向
enum class DirFour
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    MAX
};
// シーンの名前
enum class SceneName
{
	INVALID = -1,
	TITLE,
	MAIN,
	RESULT,
	OPTION,
	EXIT,

	MAX
};
// 表示レイヤー
enum class Layer
{
	INVALID = -1,
	NONE_DRAW,
	BACK_GROUND,
	OBJECT,
	PLAYER,
	ENTITY,
	EFFECT,
	UI,

	MAX
};
// 部屋の種類
enum class SectionType
{
	INVALID = -1,
	NONE,
	ROOM,
	CORRIDOR,
	CONNECT,
	SECURE,

	MAX
};
// 方向
enum class Direction
{
	INVALID = -1,
	UP,
	RIGHT,
	DOWN,
	LEFT,

	MAX
};
// 種類
enum class Type
{
	RED = 0,
	WHITE,
	BLACK,
	PALE,
	MAX
};

// ステージ
const int SECTION_SIZE = 100;

// 色
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// 便利数字
const float RAD2DEG = (float)(180 / DX_PI);