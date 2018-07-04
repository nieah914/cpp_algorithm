//============================================================================
// Name        : 2016_11_12_11053.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int number = 0;
	cin >> number;
	vector<int> container;
	vector<int>::iterator it;
	int temp;
	cin >> temp;
	container.push_back(temp);
	for (int i = 2; i <= number; i++) {
		cin >> temp;
		it = container.end()-1;
		if (temp > *it)
			container.push_back(temp);
		else {
			//bool isChange = 0;
			for (it = container.begin(); it != container.end(); it++) {
				if (temp <= *(it)) {
					*(it) = temp;
					break;
				}
			}
		}
	}
	cout<< container.size()<<endl;

	return 0;
}
