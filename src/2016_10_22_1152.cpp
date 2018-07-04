//============================================================================
// Name        : 2016_10_22_1152.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
	string temp;
	char* String = new char[1000000];
	cin.getline(String,1000000);
	int result = 0;

	for(int i = 0 ;(String[i] != 0); i++) {
		if((String[i] != ' ') && (String[i+1] ==' ')&&(String[i+1]!=0))
			result+=1;
		else if((String[i] != ' ' )&&String[i+1] == 0)
			result +=1;
	}
	cout<<result<<endl;
	return 0;
}
