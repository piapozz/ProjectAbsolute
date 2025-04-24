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
	/// <summary>
	/// ���C������
	/// </summary>
	void Proc();
	bool GetGameEnd ( );

private:
	PhaseManager* _pPhaseManager;
	ObjectManager* _pObjectManager;
	// �Q�[�����I����������ێ�
	bool _gameEnd;
};