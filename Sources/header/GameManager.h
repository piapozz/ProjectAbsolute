#pragma once
#include "DxLib.h"
#include "../header/PhaseManager.h"

/*
 * Sein
 * ���C���Q�[���̐i�s���Ǘ�
 */
class GameManager
{
public:

	GameManager();
	~GameManager();

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	bool GetGameEnd ( );

private:
	PhaseManager* _pPhaseManager;
	// �Q�[�����I����������ێ�
	bool _gameEnd;
};