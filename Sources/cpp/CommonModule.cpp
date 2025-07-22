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

Transform Transform::GetWorldTransform()
{
	Transform result;
	if (parent != nullptr)
	{
		Transform parentTransform = parent->GetTransform().GetWorldTransform();

		result.position = position * parentTransform.scale / 2 + parentTransform.position;
		result.scale = scale * parentTransform.scale;
	}
	else
	{
		result.position = position;
		result.scale = scale;
	}
	return result;
}

void Attach2DArray(std::vector<std::vector<int>>& base,
				   const std::vector<std::vector<int>>& patch,
				   AttachDirection direction,
				   Align align)
{
	if (base.empty() || patch.empty()) return;

	size_t baseRows = base.size();
	size_t baseCols = base[0].size();
	size_t patchRows = patch.size();
	size_t patchCols = patch[0].size();

	if (direction == AttachDirection::Top || direction == AttachDirection::Bottom) {
		size_t newCols = std::max<size_t>(baseCols, patchCols);
		for (auto& row : base) row.resize(newCols, 0);

		std::vector<std::vector<int>> patchResized(patch.size(), std::vector<int>(newCols, 0));
		for (size_t y = 0; y < patch.size(); ++y) {
			size_t offset = 0;
			if (align == Align::Center && patchCols < newCols)
				offset = (newCols - patchCols) / 2;
			for (size_t x = 0; x < patch[y].size(); ++x) {
				patchResized[y][x + offset] = patch[y][x];
			}
		}

		if (direction == AttachDirection::Top) {
			base.insert(base.begin(), patchResized.begin(), patchResized.end());
		} else {
			base.insert(base.end(), patchResized.begin(), patchResized.end());
		}
	} else {
		size_t newRows = std::max<size_t>(baseRows, patchRows);
		if (baseRows < newRows)
			base.resize(newRows, std::vector<int>(baseCols, 0));

		std::vector<std::vector<int>> patchResized(newRows, std::vector<int>(patchCols, 0));
		for (size_t y = 0; y < patch.size(); ++y) {
			patchResized[y] = patch[y];
		}

		if (align == Align::Center && patchRows < newRows) {
			size_t offset = (newRows - patchRows) / 2;
			patchResized = std::vector<std::vector<int>>(newRows, std::vector<int>(patchCols, 0));
			for (size_t y = 0; y < patch.size(); ++y) {
				patchResized[y + offset] = patch[y];
			}
		}

		if (direction == AttachDirection::Left) {
			for (size_t i = 0; i < newRows; ++i) {
				patchResized[i].insert(patchResized[i].end(), base[i].begin(), base[i].end());
				base[i] = patchResized[i];
			}
		} else {
			for (size_t i = 0; i < newRows; ++i) {
				base[i].insert(base[i].end(), patchResized[i].begin(), patchResized[i].end());
			}
		}
	}
}