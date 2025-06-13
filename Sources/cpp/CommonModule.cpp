#include "../header/CommonModule.h"
#include "../header/Const.h"
#include "../header/BaseObject.h"

/// <summary>
/// スクリーン座標からステージ座標に変換する
/// </summary>
/// <param name="screenPos"></param>
/// <param name="cameraHeight"></param>
/// <param name="cameraPos"></param>
/// <returns></returns>
Vector2 GetScreen2StagePos(Vector2 screenPos, float cameraHeight, Vector2 cameraPos)
{
	// 拡縮と中心座標から変換
	float ratio = cameraHeight / WINDOW_HEIGHT;
	Vector2 screenCentor = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2;
	// スクリーンの中心座標からの距離に拡縮をかけてステージの中心座標から求める
	Vector2 screenDistance = Vector2(screenPos.x - screenCentor.x, screenCentor.y - screenPos.y);
	return Vector2(cameraPos + screenDistance * ratio);
}

Vector2 Transform::GetWorldPosition()
{
	Vector2 result;
	if (parent != nullptr)
		result = position + parent->GetPosition();
	else
		result = position;
	return result;
}