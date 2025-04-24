#include "DxLib.h"
#include "../header/SceneManager.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// プログラム開始
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// このコードは標準入力と標準出力を用いたサンプルコードです。
 // このコードは好きなように編集・削除してもらって構いません。

	int daysInMonth = 18;
	int daysInYear = 1783;
	int daysInWeek = 20;
	int year = 2013 ;
	int month = 1;
	int day = 1;

	vector<vector<vector<string>>> years;

	char dash1, dash2;

	cin >> daysInYear >> daysInMonth >> daysInWeek >> year >> dash1 >> month  >> dash2 >> day;

	// 一年に何月あるか
	int monthOfYear = daysInYear / daysInMonth;
	// 一年に何日余るか
	int stockValue = daysInYear % daysInMonth;
	// 無効な月日
	float temp =  daysInYear / daysInMonth;
	if (month < 1 || month > daysInYear / daysInMonth) return -1;
	if (day < 1 || day > daysInMonth) return -1;

	vector<int> leapYear;
	int stock = 0;
	for (int i = 1; i <= year; i++)
	{
		// うるう月を計算
		stock += stockValue;
		if (stock >= daysInMonth)
		{
			leapYear.push_back(i);
			stock -= daysInMonth;
		}
	}

	// 判定する月がうるう月が判定
	if (month == (daysInYear / daysInMonth) + 1)
	{
		auto it = find(leapYear.begin(), leapYear.end(), year);
		if (it == leapYear.end()) return -1;
		else leapYear.erase(it);
	}

	// 経過日数
	long long result = 0;
	result += static_cast<long long>(year) * monthOfYear * daysInMonth;
	result += static_cast<long long>(month - 1) * daysInMonth;
	result += (day - 1);
	result += static_cast<long long>(leapYear.size()) * daysInMonth;

	int week = static_cast<int>(result % daysInWeek);
	cout << static_cast<char>(week + 'A');

	return 0;
}