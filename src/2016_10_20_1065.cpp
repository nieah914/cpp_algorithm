//============================================================================
// Name        : 2016_10_20_1065.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
 *

어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

예제 입력
110

예제 출력
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
