//============================================================================
// Name        : 2016_10_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int fibonacci(int n);
int StackNum[2];
int Memo[1000]; // n번째 피보나치수가 들어감
int main() {
	int testCase = 0;
	int Number[1000];
	int temp;
	cin >> testCase;

	for(int i = 0 ; i < testCase ; i++ ) {
		cin >> temp;
		if((temp >= 0) &&(temp <=40))
			Number[i] = temp;
	}
	for(int i = 0 ; i < testCase ; i++) {
		fibonacci(Number[i]);
		for(int i = 0 ; i < 2 ; i ++)
			cout<<StackNum[i]<<" ";
		cout<<endl;
		for(int i = 0 ; i < 2 ; i ++)
			StackNum[i] = 0 ;

	}

	return 0;
}




int fibonacci(int n) {
	if (n == 0) {
		StackNum[0]+=1;
		//printf("0");
		return 0;
	} else if (n == 1) {
		StackNum[1]+=1;
		//printf("1");
		return 1;
	} else {
		/*
		if(Memo[n] > 0)
			return Memo[n];
			*/
		Memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return Memo[n];
	}
}

