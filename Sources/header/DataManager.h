#pragma once
#include <iostream>
#include <fstream>

/*
 * Sein
 * �O���f�[�^�ɕ������ꂽ�����Ǘ�
 * Json: ���̓��̏󋵂�v���C���[�̃p�����[�^���Ǘ�
 * Csv : �����̔z�u�݂̂��Ǘ�
 */
class DataManager
{
public:

	DataManager();
	~DataManager();

	/// <summary>
	/// Csv�����[�h
	/// </summary>
	void CsvLoad();
	/// <summary>
	/// Json�����[�h
	/// </summary>
	void JsonLoad();
	/// <summary>
	/// �����œn���ꂽ�t�@�C�����Z�[�u
	/// </summary>
	void SaveFile();

};