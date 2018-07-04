//============================================================================
// Name        : 2016_10_14_1389.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 987654321
using namespace std;

void printMatrix(int**matrix, int vertexNum) {
	for (int i = 1; i <= vertexNum; i++) {
		for (int j = 1; j <= vertexNum; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main() {

	int vertexNum = 0;
	int relationNum = 0;
	int inputA, inputB = 0;
	cin >> vertexNum >> relationNum;

	int** matrix = new int*[vertexNum + 1];
	for (int i = 1; i <= vertexNum; i++)
		matrix[i] = new int[vertexNum + 1];

	for (int i = 1; i <= vertexNum; i++) {
		for (int j = 1; j <= vertexNum; j++)
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INF;
	}

	for (int i = 1; i <= relationNum; i++) {
		cin >> inputA >> inputB;
		matrix[inputA][inputB] = matrix[inputB][inputA] = 1;
	}
	/*
	 cout << " 초기화 한 메트릭스" << endl;
	 matrixPrint(matrix, vertexNum);
	 */
	/*
	for (int i = 1; i <= vertexNum; i++)
		for (int j = 1; j <= vertexNum; j++) {
			for (int k = 1; k <= vertexNum; k++)
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
		}

	cout << " 와샬 1" << endl;
	printMatrix(matrix, vertexNum);
*/
	for (int k = 1; k <= vertexNum; k++)
		for (int i = 1; i <= vertexNum; i++) {
			for (int j = 1; j <= vertexNum; j++)
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
		}
	/*
	cout << " 와샬 2" << endl;
	printMatrix(matrix, vertexNum);
	*/
	/*
	 cout << " 플루이드 와샬 알고리즘 이후 " << endl;
	 matrixPrint(matrix, vertexNum);
	 */
	/*
	 for (int i = 1; i <= vertexNum; i++)
	 for (int j = 1; j <= vertexNum; j++) {
	 if (matrix[i][j] < INF)
	 minVal[i] += matrix[i][j];
	 }
	 */
	int minTemp = INF, that_person = 0;
	for (int i = 1; i <= vertexNum; i++) {
		int bacan = 0;
		for (int j = 1; j <= vertexNum; j++)
			bacan += matrix[i][j] < INF ? matrix[i][j] : 0;
		if (bacan < minTemp) {
			minTemp = bacan;
			that_person = i;
		}
	}
	cout << that_person << endl;

	return 0;
}
