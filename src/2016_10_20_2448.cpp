//============================================================================
// Name        : 2016_10_20_2448.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
/*
 * ù° �ٿ� N�� �־�����. N�� �׻� 3*2^k ���̴�. (3, 6, 12, 24, 48, ...) (k<=10)
 *
 */
char triangle[3][5] { { ' ', ' ', '*', ' ', ' ' }, { ' ', '*', ' ', '*', ' ' },
		{ '*', '*', '*', '*', '*' } };

void recusive(char** matrix, int locationX, int locationY, int size) {
	int size_ = size;
	int location_x = locationX;
	int location_y = locationY;
	if (size == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++)
				matrix[locationX + i + 1][locationY + j + 1] = triangle[i][j];
		}
	} else {
		recusive(matrix, location_x + size_ / 2, location_y + size_, size_ / 2); // right side
		recusive(matrix, location_x + size_ / 2, location_y, size_ / 2); // left side
		recusive(matrix, location_x, location_y + size_ / 2, size_ / 2); // upper side
	}

}

int main() {
	int inputN;
	cin >> inputN;

	char** matrix = new char*[inputN + 1];				//���׸��� �׸� 2���� ��Ʈ���� ����
	for (int i = 0; i <= inputN; i++) {
		matrix[i] = new char[inputN * 2 + 1];
		memset(matrix[i], 0, sizeof(char) * (inputN * 2 + 1));
	}
	for (int i = 1; i <= inputN; i++) 					// �ʱ�ȭ
		for (int j = 1; j < (inputN * 2); j++)
			matrix[i][j] = ' ';

	recusive(matrix, 0, 0, inputN);						//��Ŀ�ú� ȣ��

	for (int i = 1; i <= inputN; i++) {					// �׸� ���
		for (int j = 1; j < (inputN * 2); j++)
			printf("%c",matrix[i][j]);
		printf("\n");
	}

	/*
	 for(int i = 0 ; i < 3; i ++) {
	 for(int j = 0 ; j< 5 ; j++)
	 cout<<triangle[i][j];
	 cout<<endl;
	 }
	 */
	return 0;
}
