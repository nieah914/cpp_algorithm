//============================================================================
// Name        : 2016_10_14_11403.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stack>
#define INF 987654321
using namespace std;

void printMatrix(int**matrix, int matrixSize) {
	for (int i = 1; i <= matrixSize; i++) {
		for (int j = 1; j <= matrixSize; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

}

int main() {
	int matrixSize = 0;
	cin >> matrixSize;

	int **matrix = new int*[matrixSize + 1];
	//매트릭스 선언 및 0으로 초기화
	for (int i = 1; i <= matrixSize + 1; i++) {
		matrix[i] = new int[matrixSize + 1];
		memset(matrix[i], 0, sizeof(int) * (matrixSize + 1));
	}
	//매트릭스 내용값 입력
	for (int i = 1; i <= matrixSize; i++) {
		for (int j = 1; j <= matrixSize; j++)
			cin >> matrix[i][j];
	}
	//플루이드 와샬 알고리즘을 통한 최소 가능 길이 확인
	for (int k = 1; k <= matrixSize; k++) {
		for (int i = 1; i <= matrixSize; i++)
			for (int j = 1; j <= matrixSize; j++) {
				if ((matrix[i][k] == 1) && (matrix[k][j] == 1))
					matrix[i][j] = 1;
			}
	}
	printMatrix(matrix, matrixSize);

	return 0;
}

