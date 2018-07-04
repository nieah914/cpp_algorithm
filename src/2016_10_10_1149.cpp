//============================================================================
// Name        : 2016_10_10_1149.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int breadNum = 0;
	int breadPrice[10001] = { 0, };
	int D[1001] = { 0, };
	int temp = 0;
	cin >> breadNum;

	if (((1 <= breadNum) && (breadNum <= 1000)))
		;
	else {
		cout <<"invalid"<<endl;
		return 0;
	}

	for (int i = 1; i <= breadNum; i++) {
		cin >> temp;
		if ((1 <= temp) && (temp <= 10000))
			breadPrice[i] = temp;
		else
			return 0;
	}
	D[1] = breadPrice[1];
	for (int i = 2; i <= breadNum; i++) {
		for (int j = 1; j <= i; j++)
			D[i] = max(D[i], D[i - j] + breadPrice[j]);
			//D[i] = max(D[i], D[j] + breadPrice[i-j]);
	}
	cout << D[breadNum];
	return 0;
}
