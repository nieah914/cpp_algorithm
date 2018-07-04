//============================================================================
// Name        : 2016_11_03_11399.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int compareFunc(const void *arg1, const void* arg2) {
	if (*(int*) arg1 > *(int*) arg2)
		return 1;
	else if (*(int*) arg1 < *(int*) arg2)
		return -1;
	else
		return 0;
}

int main() {
	int humanNum;
	cin >> humanNum;
	int* takeTime = new int[humanNum + 1];
	memset(takeTime, 0, sizeof(int) * (humanNum + 1));
	for (int i = 1; i <= humanNum; i++) {
		cin >> takeTime[i];
	}

	qsort(takeTime + 1, humanNum, sizeof(takeTime[0]), compareFunc);

	for (int i = 1; i <= humanNum; i++) {
		takeTime[i] += takeTime[i - 1];
	}
	int sum = 0;
	for (int i = 1; i <= humanNum; i++) {
		sum += takeTime[i];
	}
	cout<<sum<<endl;

}
