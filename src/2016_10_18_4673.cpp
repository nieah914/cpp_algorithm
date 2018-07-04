//============================================================================
// Name        : 2016_10_18_4673.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;
/*
int gernerator(int startNum, int* Array, queue<int>& selfNum) {
	int setNum[5] = { 0, };
	int temp;
	if (startNum == 1) {
		selfNum.push(startNum);
		temp = startNum;
		Array[1] = 0;
	}

	else {
		for (int i = 2; i <= 10000; i++) {
			if (Array[i] == 1) {
				temp = i;
				Array[temp] = 0;
				selfNum.push(temp);
				break;
			}
			if (i == 10000)
				return 0;
		}
	}
	while (temp <= 10000) {
		setNum[4] = temp / 10000;
		setNum[3] = (temp % 10000) / 1000;
		setNum[2] = (temp % 1000) / 100;
		setNum[1] = (temp % 100) / 10;
		setNum[0] = (temp % 10);
		temp += (setNum[0] + setNum[1] + setNum[2] + setNum[3] + setNum[4]);

		if (temp <= 10000)
			Array[temp] = 0;
	}
	gernerator(0, Array, selfNum);

}

int main_2() {
	int Array[10001] = { 0, };
	for (int i = 1; i <= 10000; i++)
		Array[i] = 1;
	queue<int> selfNum;
	gernerator(1, Array, selfNum);

	while (selfNum.size() > 0) {
		cout << selfNum.front() << endl;
		selfNum.pop();
	}
	return 0;
}
*/
int main() {
	int Array[10001] = { 0, };
	int setNum[5] = { 0, };
	int startNum;
	for (int i = 1; i <= 10000; i++)
		Array[i] = 1;
	for (int j = 1; j <= 10000; j++) {
		startNum = j;
		while (startNum <= 10000) {
			setNum[4] = startNum / 10000;
			setNum[3] = (startNum % 10000) / 1000;
			setNum[2] = (startNum % 1000) / 100;
			setNum[1] = (startNum % 100) / 10;
			setNum[0] = (startNum % 10);
			startNum += (setNum[0] + setNum[1] + setNum[2] + setNum[3]
					+ setNum[4]);
			if (startNum <= 10000)
				Array[startNum] = 0;

		}
	}
	for (int j = 1; j <= 10000; j++)
		if(Array[j] == 1)
			cout<<j<<endl;


	return 0;
}

