//============================================================================
// Name        : 2016_11_03_2217.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int compareFunc(const void* arg1, const void*arg2) {
	if (*(int*) arg1 > *(int*) arg2)
		return 1;
	else if (*(int*) arg1 < *(int*) arg2)
		return -1;
	else
		return 0;
}

int main() {
	int ropeNum;
	cin >> ropeNum;
	int* ropePower = new int[ropeNum + 1];
	memset(ropePower, 0, sizeof(int) * (ropeNum + 1));
	for (int i = 1; i <= ropeNum; i++)
		cin >> ropePower[i];
	qsort(ropePower + 1, ropeNum, sizeof(ropePower[0]), compareFunc);
	int maxWeigh = 0;
	int temp = 0;
	for (int i = 1; i <= ropeNum; i++) { // ·ÎÇÁÀÇ °¹¼ö
		temp = ropePower[ropeNum + 1 - i] * i;
		maxWeigh = max(maxWeigh, temp);
	}

	cout << maxWeigh;

}
