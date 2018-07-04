//============================================================================
// Name        : 2016_10_13_6359.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int calculater(int roomNum);
int main() {
	int testNum = 0;
	cin >> testNum;

	int* testCase = new int[testNum + 1];
	for (int i = 1; i <= testNum; i++)
		cin >> testCase[i];

	for (int i = 1; i <= testNum; i++) {
		cout << calculater(testCase[i]) << endl;
	}

	delete testCase;
	return 0;
}

int calculater(int roomNum) {
	int* roomArray = new int[roomNum + 1];
	int dp = 0;

//	memset(roomArray, 0, sizeof(roomArray)); // 문을 모두 열어줌 실수한거
	//memset(roomArray, 0, sizeof(int)*(roomNum+1)); // 문을 모두 열어줌 0말고는 초기화 안됨 씨발
	for (int i = 1; i <= roomNum; i++)
		roomArray[i] = 1;

	for (int i = 2; i <= roomNum; i++) {
		for (int j = 1; j*i <= roomNum;j++ ) {
			if (roomArray[j*i] == 1)
				roomArray[j*i] = 0;
			else if (roomArray[j*i] == 0)
				roomArray[j*i] = 1;
		}
	}
	for (int i = 1; i <= roomNum; i++)
		dp += roomArray[i];

	delete roomArray;

	return dp;
}

