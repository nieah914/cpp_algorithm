//============================================================================
// Name        : 2016_10_27_4485.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#define INF 100000
using namespace std;

void printMat(int** matrix, int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (matrix[i][j] == INF)
				cout << "F  ";
			else if (matrix[i][j] >= 10)
				cout << matrix[i][j] << " ";
			else
				cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() {
	int matrixSize;
	int container[1000] = { 0, };
	int counter = 0;
	while (cin >> matrixSize) {
		if (matrixSize == 0)
			break;
		counter += 1;
		//인풋값을 통한 맵을 작성
		//make map matrix
		int** mapMatrix = new int*[matrixSize + 1];
		for (int i = 1; i <= matrixSize; i++) {
			mapMatrix[i] = new int[matrixSize + 1];
			memset(mapMatrix[i], 0, sizeof(int) * (matrixSize + 1));
		}

		// initialize map
		for (int i = 1; i <= matrixSize; i++) {
			for (int j = 1; j <= matrixSize; j++) {
				cin >> mapMatrix[i][j];
			}
		}

		//printMat(mapMatrix, matrixSize);

		int **mapAccumul = new int*[matrixSize * matrixSize + 1];

		for (int i = 1; i <= matrixSize * matrixSize; i++) {
			mapAccumul[i] = new int[matrixSize * matrixSize + 1];
			memset(mapAccumul[i], 0,
					sizeof(int) * (matrixSize * matrixSize + 1));
		}

		for (int i = 1; i <= matrixSize * matrixSize; i++) {
			for (int j = 1; j <= matrixSize * matrixSize; j++) {
				if (i == j)
					mapAccumul[i][j] = 0;
				else {
					mapAccumul[i][j] = INF;
				}
			}
		}

		//map compelte for dycstra
		for (int i = 1; i <= matrixSize; i++) {
			for (int j = 1; j <= matrixSize; j++) {
				if ((i >= 2) && (i <= matrixSize)) {
					mapAccumul[(i - 1) * matrixSize + j][(i - 2) * matrixSize
							+ j] = mapMatrix[i - 1][j];
				}
				if ((i >= 1) && (i < matrixSize)) {
					mapAccumul[(i - 1) * matrixSize + j][(i) * matrixSize + j] =
							mapMatrix[i + 1][j];
				}
				if ((j >= 2) && (j <= matrixSize)) {
					mapAccumul[(i - 1) * matrixSize + j][(i - 1) * matrixSize
							+ j - 1] = mapMatrix[i][j - 1];
				}
				if ((j >= 1) && (j < matrixSize)) {
					mapAccumul[(i - 1) * matrixSize + j][(i - 1) * matrixSize
							+ j + 1] = mapMatrix[i][j + 1];
				}
//			printMat(mapAccumul,matrixSize*matrixSize);
//					cout << endl;
			}
		}
		int temp;
		//위로 올라가는거에 대한걸 안해주니까 윗방향 올라갈때 계산을 제대로 못함
		/*
		 for (int k = 1; k <= matrixSize * matrixSize; k++) {
		 for (int i = 1; i <= matrixSize * matrixSize; i++) {
		 for (int j = 1; j <= matrixSize * matrixSize; j++) {
		 if ((mapAccumul[k][j] != INF) && (mapAccumul[j][i] != INF)) {
		 temp = mapAccumul[k][j] + mapAccumul[j][i];
		 if (mapAccumul[k][i] > temp)
		 mapAccumul[k][i] = temp;
		 }
		 }
		 }
		 }
		 */
		for (int k = 1; k <= matrixSize * matrixSize; k++) {
			for (int i = 1; i <= matrixSize * matrixSize; i++) {
				/*
				for (int j = 1; j <= matrixSize * matrixSize; j++) {
					if ((mapAccumul[k][j] != INF)
							&& (mapAccumul[j][i] != INF)) {
						temp = mapAccumul[k][j] + mapAccumul[j][i];
						if (mapAccumul[k][i] > temp)
							mapAccumul[k][i] = temp;
					}
				}
				*/
			}
			for (int i = 1; i <= matrixSize * matrixSize; i++) {
				for (int j = 1; j <= matrixSize * matrixSize; j++) {
					if ((mapAccumul[matrixSize * matrixSize-k+1][j] != INF)
							&& (mapAccumul[j][i] != INF)) {
						temp = mapAccumul[matrixSize * matrixSize-k+1][j] + mapAccumul[j][i];
						if (mapAccumul[matrixSize * matrixSize-k+1][i] > temp)
							mapAccumul[matrixSize * matrixSize-k+1][i] = temp;
					}
				}
			}

		}
/*
		for (int k = matrixSize * matrixSize; k >= 1; k--) {
			for (int i = 1; i <= matrixSize * matrixSize; i++) {
				for (int j = 1; j <= matrixSize * matrixSize; j++) {
					if ((mapAccumul[k][j] != INF)
							&& (mapAccumul[j][i] != INF)) {
						temp = mapAccumul[k][j] + mapAccumul[j][i];
						if (mapAccumul[k][i] > temp)
							mapAccumul[k][i] = temp;
					}
				}
			}
		}
		*/
		container[counter] = mapAccumul[1][matrixSize * matrixSize]
				+ mapMatrix[1][1];
//	printMat(mapAccumul,matrixSize*matrixSize);

	}
	for (int i = 1; i <= counter; i++)
		printf("Problem %d: %d\n",i,container[i]);

	return 0;
}
