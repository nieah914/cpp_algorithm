//============================================================================
// Name        : q1018.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int x, y;
	string temp;

	cin >> x >> y;

	int** matrix = new int*[x];
	int** smallMap = new int*[8];
	int * containerA = new int[x * y];
	int * containerB = new int[x * y];
	fill_n(containerA, x * y, 0);
	fill_n(containerB, x * y, 0);
	int compare_typeA[8] = { 1, -1, 1, -1, 1, -1, 1, -1 };
	int compare_typeB[8] = { -1, 1, -1, 1, -1, 1, -1, 1 };

	//¿€¿∫ ∏  ∏∏µÍ
	for (int i = 0; i < 8; i++) {
		smallMap[i] = new int[8];
		memset(smallMap[i], '0', sizeof(int) * 8);
	}

	//≈´ ∏  ∏∏µÍ
	for (int i = 0; i < x; i++) {
		matrix[i] = new int[y];
		memset(matrix[i], 'O', sizeof(int) * y);
	}

	for (int i = 0; i < x; i++) {
		cin >> temp;
		for (int j = 0; j < y; j++) {
			if (temp[j] == 'B')
				matrix[i][j] = 1;
			else
				matrix[i][j] = -1;
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout<<"x = " <<x<<endl;
	int numConA = 0;
	int numConB = 0;
	int conclude = x * y;
	for (int i = 0; i < x - 7; i++) {
		for (int j = 0; j < y - 7; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					smallMap[k][l] = matrix[i + k][j + l];
				}
			}

			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {
					if (n % 2 == 0) {
						numConA += (smallMap[n][m] + compare_typeA[m]);
						numConB += (smallMap[n][m] + compare_typeA[m]);
					} else {
						numConA += (smallMap[n][m] + compare_typeB[m]);
						numConB += (smallMap[n][m] + compare_typeB[m]);
					}

				}

			}
			if (conclude > numConA)
				conclude = numConA;
			if (conclude > numConB)
				conclude = numConB;

			numConA = 0;
			numConB = 0;

		}

	}
	cout << conclude;

	return 0;
}
