//============================================================================
// Name        : 2016_10_13_1104.cpp
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
	int N, M = 0;
	int valCase1 = 0;
	int valCase2 = 0;
	int valCase3 = 0;

	cin >> N >> M;

	int **Miro = new int*[N+1];
	int **Dp = new int*[N+1];
	for(int i = 0 ; i <= N ; i++) {
		Miro[i] = new int[M+1];
		Dp[i] = new int[M+1];
		memset(Miro[i], 0, sizeof(int)*(M+1));
		memset(Dp[i], 0, sizeof(int)*(M+1));
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> Miro[i][j];
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1 ; j <= M; j++) {
			valCase1 = Dp[i - 1][j] + Miro[i][j];
			valCase2 = Dp[i][j - 1] + Miro[i][j];
			valCase3 = Dp[i - 1][j - 1] + Miro[i][j];
			Dp[i][j] = max(valCase1, valCase2);
			Dp[i][j] = max(Dp[i][j], valCase2);
		}

	cout << Dp[N][M];



	for(int i = 0 ; i <= N ; i++) {
		delete [] Miro[i];
		delete [] Dp[i];
	}
	delete [] Miro;
	delete [] Dp;

	return 0;

}
