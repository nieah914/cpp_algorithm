//============================================================================
// Name        : 2016_11_17_1110.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int initial = 0;
	int usingNum = 0;

	int frontNum;
	int laterNum;
	int temp;
	int lenth = 0;
	cin >> initial;
	usingNum = initial;
	while(1) {
		frontNum = usingNum / 10;
		laterNum = usingNum % 10;
		temp = frontNum + laterNum;
		temp %= 10;
		usingNum = laterNum*10 + temp;
		lenth +=1;
		if(initial == usingNum)
			break;
	}
	cout << lenth <<endl;
	return 0;
}
