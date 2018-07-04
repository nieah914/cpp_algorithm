//============================================================================
// Name        : 2016_10_23_2947_bubble_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int container[6] = {0,};
	int temp = 0;
	for(int i = 1; i <= 5 ; i++)
		cin >> container[i];

	for(int i = 1; i <= 5 ; i++) {
		for(int j = 1 ; j<= 4 ; j++)
			if(container[j] > container[j+1]) {
				temp = container[j+1];
				container[j+1] = container[j];
				container[j] = temp;
				for(int i = 1; i <= 5 ; i++)
					cout<<container[i]<<" ";
				cout<<endl;
			}

	}
	return 0;
}
