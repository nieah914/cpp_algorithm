//============================================================================
// Name        : 2016_11_15_2352.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int numbers;
	cin >> numbers;

	vector<int> contaianer;
	vector<int>::iterator it;

	int temp;
	cin >> temp;
	contaianer.push_back(temp);

	for (int i = 2; i <= numbers; i++) {
		cin >> temp;

		if(temp > contaianer.back()) {
			contaianer.push_back(temp);
		}
		else {
			for (it = contaianer.begin(); it != contaianer.end(); it++) {
				if (temp < (*it)) {
					*it = temp;
					break;
				}
			}
		}
	}
	cout<<contaianer.size()<<endl;
}


