//============================================================================
// Name        : 2016_10_12_1149.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int Dp[1001][4] = {0,};
	int HouseNum = 0;
	int colorPrice[1001][4] = {0,};
	int minimamPrice = 0;

	cin >> HouseNum;
	for(int i = 1 ; i <= HouseNum ; i++)
		cin >> colorPrice[i][1] >>colorPrice[i][2] >>colorPrice[i][3];

	Dp[1][1] = colorPrice[1][1];
	Dp[1][2] = colorPrice[1][2];
	Dp[1][3] = colorPrice[1][3];
	for(int i = 2; i <= HouseNum ; i++) {
		Dp[i][1] = min(Dp[i-1][2] + colorPrice[i][1],Dp[i-1][3] + colorPrice[i][1]);
		Dp[i][2] = min(Dp[i-1][3] + colorPrice[i][2],Dp[i-1][1] + colorPrice[i][2]);
		Dp[i][3] = min(Dp[i-1][1] + colorPrice[i][3],Dp[i-1][2] + colorPrice[i][3]);
	}
	minimamPrice = Dp[HouseNum][1];
	for(int i = 1 ; i <= 3 ; i ++) {
		minimamPrice = min(minimamPrice,Dp[HouseNum][i]);
	}
	cout<< minimamPrice<<endl;


	return 0;
}
