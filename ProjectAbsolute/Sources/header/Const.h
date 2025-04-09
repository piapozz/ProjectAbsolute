#pragma once
#include <math.h>
#include <vector>
#include <string>
#include "DxLib.h"

// 二次元ベクトル
struct Vector2
{
public:
    float x;
    float y;

    Vector2 operator+(const Vector2& vec) const
    {
        Vector2 temp;

        temp.x = x + vec.x;
        temp.y = y + vec.y;

        return temp;
    }

    Vector2 operator-(const Vector2& vec) const
    {
        Vector2 temp;

        temp.x = x - vec.x;
        temp.y = y - vec.y;

        return temp;
    }

    Vector2 operator*(const Vector2& vec) const
    {
        Vector2 temp;

        temp.x = x * vec.x;
        temp.y = y * vec.y;

        return temp;
    }

    Vector2 operator+(const float& num) const
    {
        Vector2 temp;

        temp.x = x + num;
        temp.y = y + num;

        return temp;
    }

    Vector2 operator-(const float& num) const
    {
        Vector2 temp;

        temp.x = x - num;
        temp.y = y - num;

        return temp;
    }

    Vector2 operator*(const float& num) const
    {
        Vector2 temp;

        temp.x = x * num;
        temp.y = y * num;

        return temp;
    }

    Vector2 operator/(const float& num) const
    {
        Vector2 temp;

        temp.x = x / num;
        temp.y = y / num;

        return temp;
    }

    Vector2()
    {
        x = 0;
        y = 0;
    }

    Vector2(const float& X, const float& Y)
    {
        x = X;
        y = Y;
    }

    static float Distance(const Vector2& vec1, const Vector2& vec2)
    {
        return Size(vec1 - vec2);
    }

    inline float size() const
    {
        return sqrtf(powf(x, 2) + powf(y, 2));
    }

    inline static float Size(const Vector2& vec)
    {
        return sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
    }

    void normalize()
    {
        float distance = size();

        if (distance == 0) return;
        
        x /= distance;
        y /= distance;
    }

    inline static Vector2 Normalize(const Vector2& vec)
    {
        Vector2 temp;
        float distance = vec.size();

        temp.x = vec.x / distance;
        temp.y = vec.y / distance;

        return temp;
    }

    inline static float Dot(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.x * vec2.x + vec2.y * vec1.y;
    }

    inline static float Cross(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.x * vec2.y - vec2.x * vec1.y;
    }
};

// 弾のステータス
enum class BulletStatus
{
    SPEED,
    POWER,
    RANGE,
    RATE,

    MAX
};

// 弾のタイプ
enum class BulletType
{
    NORMAL,
    EXPLOSION,
    MULTI_SHOT,
    PENETRATION,
    REFLECTION,

    MAX
};
enum class DirButton
{
    DOWN = 0,
    LEFT,
    RIGHT,
    UP,
    MAX
};

enum class Button
{
	X = 0,
	Y,
	A,
	B,
	LEFT_BUTTON,
	RIGHT_BUTTON,
	LEFT_TRIGGER,
	RIGHT_TRIGGER,
	LEFT_STICK_BUTTON,
	RIGHT_STICK_BUTTON,

	MAX
};

enum class Stick
{
	LEFT = 0,
	RIGHT,
	MAX
};

enum class Shape				// 当たり判定の形区別するための情報
{
    CIRCLE = 0,
    SQUARE,
    MAX
};

// 方位
enum class Cardinal
{
    WEST,
    NORTH,
    EAST,
    SOUTH,
    MAX
};

enum class ObjectType
{
    PLAYER = 0,
    BOX,
    WALL,
    BULLET,
    MAX
};

enum class BGMName
{
    IN_GAME = 0,

    MAX
};

enum class SEName
{
    SHOT = 0,
    IMPACT,
    LEVELUP,
    LEVELUP_DECIDE,
    EXPLOSION,
    DAMAGE,
    DODGE,
    REFLECT,
    BOMB,
    CURSOR_DECIDE,
    CURSOR_MOVE,
    GAMEEND,

    MAX
};

enum class UIGraph
{
    STATUS_DIA_BASE = 0,
    STATUS_DIA,

    MAX,
};

// プレイヤー
const int PLAYER_MAX = 2;		// プレイヤーの最大数
const std::string PLAYER_GRAPH_ADRESS[PLAYER_MAX] =
{
    "Resources/Player_1.png",
    "Resources/Player_2.png"
};

// 弾
const std::string BULLET_GRAPH_ADRESS[PLAYER_MAX] =
{
    "Resources/Bullet_1.png",
    "Resources/Bullet_2.png"
};

const std::string UI_GRAPH_ADRESS[(int)UIGraph::MAX] =
{
    "Resources/Status_Dia_Base.png",
    "Resources/Status_Dia.png",
};

// 箱
const float BOX_SIZE = 100.0f;   // 箱のサイズ
const int REVIVAL_TIME = 2000;   // 復活までの時間
const float BOX_LIFE = 10.0f;
const int BOX_HIT_COUNT = 10;
const float BOX_HIT_SCALE = 0.2f;
const std::string BOX_GRAPH_ADRESS = "Resources/Box.png";
const std::string WALL_GRAPH_ADRESS = "Resources/Wall.png";

// 色データ
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);

// ステージ
const float STAGE_MARGIN_RATE = 0.1f;

// ウィンドウ
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// UI関連
const int CHOICE_POWER_MAX = 3;
const int CHOICE_STATUS_MAX = 3;

const float BULLET_ICON_WIDTH = 75.0f;
const float BULLET_ICON_HEIGHT = 75.0f;

const int FONT_DEFAULT = 20;

const float RAD = (float)(180 / DX_PI);

const float DISTANCE_ERROR = 50.0f;
const float BAR_TO_BAR_ERROR = 7.0f;
const float LEVEL_BAR_HEIGHT = BULLET_ICON_WIDTH / 3;
const float LEVEL_BAR_WIDTH = BULLET_ICON_HEIGHT / 3;

const float TYPE_ICON_HEIGHT = 50.0f;
const float TYPE_ICON_WIDTH = 50.0f;

const int TEXT_TO_STAR = 10;
const int STAR_TO_STAR = 20;

const Vector2 TYPE_ICON = { TYPE_ICON_HEIGHT / 2 ,TYPE_ICON_WIDTH / 2 };

// プレイヤー関連
const float DODGE_COOLTIME = 2000.0f;
const float DODGE_MOVETIME = 250.0f;

const float PLAYER_BOMB_TIME = 1000.0f;
const int LEVEL_MAX = 10;

extern Vector2 drawAnchorPos;				// ステージのアンカー座標
extern float drawRatio;