#pragma once
#include "DxLib.h"
#include "../header/FaseManager.h"

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
	FaseManager _faseManager;
	// �Q�[�����I����������ێ�
	bool _gameEnd;

	GameManager();
	~GameManager();
};