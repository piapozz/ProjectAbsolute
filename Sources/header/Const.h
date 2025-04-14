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
	ROOM,
	SECURE,
	CORRIDOR,
	CONNECT,

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
// 作業の種類
enum class OperationType
{
	SATISFY = 0,
	OBSERVATION,
	CONTACT,
	INJURE
};
// 収容室の状態
enum class State
{
	NONE,
	IDLE,
	OPERATE,
	EMERGENCY,
};

// 色
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// 便利数字
const float RAD = (float)(180 / DX_PI);