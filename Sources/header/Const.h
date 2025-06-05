#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "CommonModule.h"

enum class ObjectType{
	INVALID = -1,
	SCREEN_UI,
	UI,
	CHARACTER,
	SECTION,

	MAX
};
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
	BACK,
	MIDDLE,
	FRONT,

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
// 種類
enum class Type
{
	INVALID = -1,
	RED,
	WHITE,
	BLACK,
	PALE,
	MAX
};

enum class OfficerType
{
	NONE = -1,
	PLAYER,
	MOB,

	MAX
};

enum class CharacterStateID
{
	NONE = -1,
	IDLE,
	MOVE,
	OPERATION,
	OPERATION_MOVE,
	FIGHT,
	PANIC,
	DEAD,

	MAX
};

enum class CharacterGroup
{
	INVALID = -1,
	OFFICER,
	ENTITY,
	OTHER,
};

// UI設定構造体
typedef struct UISetting{
	Vector2 m_position = Vector2::zero();	// 座標
	Vector2 m_size = Vector2::zero();		// 大きさ
	std::string m_text = "";				// テキスト内容
	bool m_fill = true;						// 塗りつぶしフラグ
};

// レイヤー設定構造体
typedef struct LayerSetting
{
	bool m_active = true;
	bool m_interact = true;
	Layer m_layer = Layer::BACK;
	// デフォルトコンストラクタ
	LayerSetting(bool active, bool interact, Layer layer): m_active(active), m_interact(interact), m_layer(layer){ }
};

// ステージ
const int SECTION_SIZE_X = 150;
const int SECTION_SIZE_Y = 100;
// ステージのサイズ
const int STAGE_SIZE = 7;

// 色
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// 便利数字
const float RAD2DEG = (float)(180 / DX_PI);

// ステータス関係
const int MINIMUM_HEALTH = 0;
const int MINIMUM_MENTAL = 0;