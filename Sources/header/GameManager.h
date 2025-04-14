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
	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// ���C������
	/// </summary>
	void Proc();
	bool GetGameEnd ( );

private:
	PhaseManager _phaseManager;
	// �Q�[�����I����������ێ�
	bool _gameEnd;

	GameManager();
	~GameManager();
};