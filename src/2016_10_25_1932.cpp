//============================================================================
// Name        : 2016_10_25_1932.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {

	int TriangleSize = 0;
	cin >> TriangleSize;	//recive TriangleSize

	int** matrix = new int*[TriangleSize + 1];
	for (int i = 1; i <= TriangleSize; i++) {
		matrix[i] = new int[i + 1];
		memset(matrix[i], 0, sizeof(int) * (i + 1));
	}

	int** sumMat = new int*[TriangleSize + 1];
	for (int i = 1; i <= TriangleSize; i++) {
		sumMat[i] = new int[i + 1];
		memset(sumMat[i], 0, sizeof(int) * (i + 1));
	}

	for (int i = 1; i <= TriangleSize; i++) {
		for (int j = 1; j <= i; j++)
			cin >> matrix[i][j];
	}
	int temp;
	int temp2;
	int result = 0;
	sumMat[1][1] = matrix[1][1];
	for (int i = 1; i <= TriangleSize - 1; i++) {
		for (int j = 1; j <= i; j++) {
			temp = sumMat[i][j] + matrix[i+1][j];
			sumMat[i+1][j] = max(sumMat[i+1][j], temp);
			temp2 = sumMat[i][j] + matrix[i+1][j+1];
			sumMat[i+1][j+1] = max(sumMat[i+1][j+1], temp2);
		}
	}

	for(int i = 1; i <= TriangleSize ; i++) {
		result = max(result,sumMat[TriangleSize][i]);
	}

	cout << result;

	return 0;
}
