//============================================================================
// Name        : 2016_10_23_9507_Dynamic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;




int main() {
	int testCaseNum = 0;
	cin >> testCaseNum;   // input the testcase num
	long long* D = new long long[68];
	memset(D,0,sizeof(long long)*68);
	int* testCase = new int[testCaseNum+1];
	for(int i = 1 ; i<= testCaseNum ; i++) // input the Testcase
		cin >> testCase[i];

	D[0] = 1; //set initializing
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for(int i = 4; i <= 67 ; i++) // calculate
		D[i] = D[i-1] + D[i-2] + D[i-3] + D[i-4];

	for(int i = 1; i <= testCaseNum ; i ++) {
		int temp = testCase[i];
		cout<<D[temp]<<endl;
	}

	return 0;
}
