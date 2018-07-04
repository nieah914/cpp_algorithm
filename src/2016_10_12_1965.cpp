//============================================================================
// Name        : 2016_10_12_1965.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int BoxNum = 0;
	int BoxEachNum[1001] = { 0, };
	int BoxMaxNum[1001] = { 0, };
	int MaxNum = 1;

	cin >> BoxNum;
	for (int i = 1; i <= BoxNum; i++) {
		cin >> BoxEachNum[i];
		BoxMaxNum[i] = 1;
	}

	for (int i = 2; i <= BoxNum; i++) {
		for (int j = 1; j < i; j++) {
			if ((BoxEachNum[i] > BoxEachNum[j])) {
				if ((BoxMaxNum[i] - 1) >= BoxMaxNum[j])
					;
				else
					BoxMaxNum[i] = BoxMaxNum[j] + 1;
				MaxNum = max(MaxNum, BoxMaxNum[i]);
			}

		}
	}

	cout << MaxNum;

	return 0;
}
