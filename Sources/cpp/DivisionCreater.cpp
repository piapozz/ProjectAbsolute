#include "../header/DivisionCreater.h"
#include "../header/ObjectFactory.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"

Division* DivisionCreater::CreateDivision(Vector2 anchor)
{
	// 使用前に visited を初期化
	_visited = std::vector<std::vector<bool>>(
		// _stageData の行数に合わせる
		_divisionPreset.size(),
		// _stageData の列数に合わせる
		std::vector<bool>(_divisionPreset[0].size(), false)
	);

	ObjectFactory& factory = ObjectFactory::Instance();
	std::vector<BaseSection*> _roomList;
	std::vector<SecureRoom*> _secureRoomList;
	BaseSection* respawnPoint = nullptr;

	// ステージの生成
	for (int i = 0; i < _divisionPreset.size(); ++i)
	{
		for (int j = 0; j < _divisionPreset[i].size(); ++j)
		{
			if (_visited[i][j]) continue;
			LayerSetting layerSetting = LayerSetting(true, true, Layer::BACK);

			switch (_divisionPreset[i][j])
			{
				case (int)SectionType::ROOM:
				{
					// 部屋を生成
					int size = CheckSectionSize(j, i, SectionType::ROOM);
					Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y) + anchor;
					Transform transform = Transform(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
					SectionRoom* room = factory.CreateWithArgs<SectionRoom>(transform, layerSetting);
					_roomList.push_back(room);
					break;
				}
				case (int)SectionType::CORRIDOR:
				{
					// 廊下を生成
					int size = CheckSectionSize(j, i, SectionType::CORRIDOR);
					Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + 1 / 2.0f) * SECTION_SIZE_Y) + anchor;
					Transform transform = Transform(pos, Vector2(size * SECTION_SIZE_X, 1 * SECTION_SIZE_Y));
					SectionCorridor* corrider = factory.CreateWithArgs<SectionCorridor>(transform, layerSetting);
					_roomList.push_back(corrider);
					break;
				}
				case (int)SectionType::CONNECT:
				{
					// 接合部を生成
					int size = CheckSectionSize(j, i, SectionType::CONNECT);
					Vector2 pos = Vector2((j + 1 / 2.0f)* SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y) + anchor;
					Transform transform = Transform(pos, Vector2(1 * SECTION_SIZE_X, size * SECTION_SIZE_Y));
					SectionConnect* connect = factory.CreateWithArgs<SectionConnect>(transform, layerSetting);
					break;
				}
				case (int)SectionType::SECURE:
				{
					// 収容所を生成
					int size = CheckSectionSize(j, i, SectionType::SECURE);
					Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y) + anchor;
					LayerSetting layerSetting = LayerSetting(false, true, Layer::BACK);
					Transform transform = Transform(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
					SecureRoom* secure =  factory.CreateWithArgs<SecureRoom>(transform, layerSetting);
					// 収容所のリストに追加
					_secureRoomList.push_back(secure);
					break;
				}
				case (int)SectionType::RESPAWN:
				{
					// 部屋を生成
					int size = CheckSectionSize(j, i, SectionType::RESPAWN);
					Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y) + anchor;
					Transform transform = Transform(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
					SectionRoom* room = factory.CreateWithArgs<SectionRoom>(transform, layerSetting);
					_roomList.push_back(room);
					// リスポーン地点を設定
					respawnPoint = room;
					break;
				}
				default:
					break;
			}
		}
	}

	if(respawnPoint == nullptr)
	{
		// リスポーン地点が設定されていない場合はエラー
	 	return nullptr;
	}
	// 区画の設定
	Division* division = new Division(respawnPoint);
	division->SetRoomList(_roomList);
	division->SetSecureRoomList(_secureRoomList);

	return division;
}

int DivisionCreater::CheckSectionSize(int x, int y, SectionType type)
{
	// 範囲外チェック
	if (y < 0 || y >= _divisionPreset.size() || x < 0 || x >= _divisionPreset[y].size())
		return 0;
	// 既に訪れている or 種類が異なる場合は無視
	if (_visited[y][x] || _divisionPreset[y][x] != (int)type)
		return 0;
	_visited[y][x] = true;

	int count = 1;
	// 上下左右に再帰
	count += CheckSectionSize(x, y - 1, type);
	count += CheckSectionSize(x, y + 1, type);
	count += CheckSectionSize(x - 1, y, type);
	count += CheckSectionSize(x + 1, y, type);

	return count;
}