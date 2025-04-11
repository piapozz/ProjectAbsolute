#pragma once
#include "DxLib.h"
#include "vector"
#include "../header/DataManager.h"

/*
 * Sein
 * ���C���Q�[���̐i�s���Ǘ�
 */
class GameManager
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// ���C������
	/// </summary>
	void Proc();

private:
	struct EntityRooms
	{

	};

	struct DayData
	{
		int date;
		std::vector<EntityRooms> entityRoomList;
	};

	// �Q�[�����I����������ێ�
	bool _gameEnd;

	bool CheckGameEnd();
};