//============================================================================
// Name        : 2016_10_22_2577.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a=0;
	int b=0;
	int c=0;
	int lacationNumCon[10];
	int mux = 0;
	int criteria = 1;
	int location = 0;
	cin >> a >> b >> c;
	mux = a*b*c;

	// �� �ڸ����� �� ������ ���ϴ°�
	while(true) {
		if((mux/criteria) != 0) {
			criteria*=10;
			location +=1;
		}
		else
			break;
	}

	//���ڸ����� ���ڸ� Array�� ���� ����
	int cri = 1;
	int temp= 0;
	for(int i = location ; i >= 1 ; i--) {
		for(int j = 2; j <= cri ; j++)
			cri*=10;
		lacationNumCon[i] = mux/cri;
		temp = mux/cri;
	}



	return 0;
}
