//============================================================================
// Name        : 2016_10_23_9084_Dynamic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int TestCase = 0;
	cin >> TestCase;
	for (int i = 1; i <= TestCase; i++) {
		int CoinNum = 0;
		cin >> CoinNum;
		int* CoinVal = new int[CoinNum + 1];
		for (int i = 1; i <= CoinNum; i++)
			cin >> CoinVal[i];
		int DefiNum = 0;

		cin >> DefiNum;
		int** D = new int*[DefiNum + 1];
		for(int i = 0 ; i <= DefiNum ; i++) {
			D[i] = new int[CoinNum+1];
			memset(D[i], 0, sizeof(int)*(CoinNum + 1));
		}

		for (int i = 1; i <= DefiNum; i++) {
			for (int j = 1; j <= CoinNum; j++) {

				int *tempmt = new int[CoinNum+1];	// 비교위한 임시 매트릭스
				memset(tempmt,0,sizeof(int)*(CoinNum+1));

				int temp;
				temp = CoinVal[j];
				cout<<temp<<endl;

				if(((D[i-temp][0] == 0)&& ((i-temp) != 0 ))&& ((i-temp)>0))
					cout<<"here"<<endl;
				/*
				else if( (i-temp) == 0) {
					D[i][0] += 1;
					D[i][temp] += 1;
				}
				else
				{

					cout << "hello" << endl;

					for(int k = 0 ; k<= CoinNum ; k++)
						tempmt[k] = D[i-temp][k];
					//memcpy(tempmt,D[i-temp],sizeof(int));

					tempmt[temp] += 1;
					if(memcmp(D[i],tempmt,sizeof(int)*(CoinNum)));
					else {
						memcpy(D[i],tempmt,sizeof(int)*(CoinNum));
						D[i][0] +=1;

					}

				}
				 	*/
				delete tempmt;
			}
		}

		//cout<<D[DefiNum][0] <<endl;
	}

	return 0;
}
