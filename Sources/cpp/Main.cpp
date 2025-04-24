#include "DxLib.h"
#include "../header/SceneManager.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// �v���O�����J�n
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ���̃R�[�h�͕W�����͂ƕW���o�͂�p�����T���v���R�[�h�ł��B
 // ���̃R�[�h�͍D���Ȃ悤�ɕҏW�E�폜���Ă�����č\���܂���B

	int daysInMonth = 18;
	int daysInYear = 1783;
	int daysInWeek = 20;
	int year = 2013 ;
	int month = 1;
	int day = 1;

	vector<vector<vector<string>>> years;

	char dash1, dash2;

	cin >> daysInYear >> daysInMonth >> daysInWeek >> year >> dash1 >> month  >> dash2 >> day;

	// ��N�ɉ������邩
	int monthOfYear = daysInYear / daysInMonth;
	// ��N�ɉ����]�邩
	int stockValue = daysInYear % daysInMonth;
	// �����Ȍ���
	float temp =  daysInYear / daysInMonth;
	if (month < 1 || month > daysInYear / daysInMonth) return -1;
	if (day < 1 || day > daysInMonth) return -1;

	vector<int> leapYear;
	int stock = 0;
	for (int i = 1; i <= year; i++)
	{
		// ���邤�����v�Z
		stock += stockValue;
		if (stock >= daysInMonth)
		{
			leapYear.push_back(i);
			stock -= daysInMonth;
		}
	}

	// ���肷�錎�����邤��������
	if (month == (daysInYear / daysInMonth) + 1)
	{
		auto it = find(leapYear.begin(), leapYear.end(), year);
		if (it == leapYear.end()) return -1;
		else leapYear.erase(it);
	}

	// �o�ߓ���
	long long result = 0;
	result += static_cast<long long>(year) * monthOfYear * daysInMonth;
	result += static_cast<long long>(month - 1) * daysInMonth;
	result += (day - 1);
	result += static_cast<long long>(leapYear.size()) * daysInMonth;

	int week = static_cast<int>(result % daysInWeek);
	cout << static_cast<char>(week + 'A');

	return 0;
}