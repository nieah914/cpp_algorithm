//============================================================================
// Name        : 2016_10_20_1065.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
 *

� ���� ���� X�� �ڸ����� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. ���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� 1,000���� �۰ų� ���� �ڿ��� N�� �־�����.

���
ù° �ٿ� 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����Ѵ�.

���� �Է�
110

���� ���
99
 */
#include <iostream>
using namespace std;
int main() {
	int inputData = 0;
	cin >> inputData;
	int positionNum[4] = {0,};
	int counter = 0;

	for (int i = 1; i <= inputData; i++) {
		positionNum[0] = i/1000;
		positionNum[1] = (i % 1000)/100;
		positionNum[2] = (i % 100)/10;
		positionNum[3] = (i % 10);
		if (i < 100)
			counter += 1;
		else if (((positionNum[2] - positionNum[3])
				== (positionNum[1] - positionNum[2]))&&i!=1000)
			counter += 1;

	}
	cout<< counter;
	return 0;
}
