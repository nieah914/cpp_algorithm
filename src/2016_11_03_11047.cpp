//============================================================================
// Name        : 2016_11_03_11047.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int CoinNum = 0;
	int AimVal = 0;
	int totalCoin = 0;
	cin >> CoinNum >> AimVal;



	int* coinValArray = new int[CoinNum +1];
	memset(coinValArray,0,sizeof(int)*(CoinNum+1));

	for(int i = 1 ; i <= CoinNum ; i++)
		cin >> coinValArray[i];

	int i = CoinNum;

	while(1) {

		if(coinValArray[i] > AimVal)
			i-=1;
		else if(coinValArray[i] <= AimVal) {
			AimVal -= coinValArray[i];
			totalCoin+=1;
		}
		if((i == 0) ||(AimVal == 0))
			break;
	}

	cout<<totalCoin<<endl;

	return 0;
}
