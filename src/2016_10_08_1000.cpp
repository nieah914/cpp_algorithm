//============================================================================
// Name        : 2016_10_08_1000.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#define MAX 365
using namespace std;

int main() {
	int x,y = 0;
	int dayArray[13][32];
	int counter = 0;
	int mondefine= 0;
	cin >> x >> y;
	if((1<=x && x<=12) && 1<=y && y<=31) {
		for(int i = 1; i <= 12 ; i++) {
			if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 ) {
				for(int j = 1; j <= 31 ; j++) {
					counter+=1;
					mondefine= counter%7;
					dayArray[i][j]=mondefine;
				}
			}
			else if(i == 2) {
				for(int j = 1; j <= 28 ; j++) {
					counter+=1;
					mondefine= counter%7;
					dayArray[i][j]=mondefine;
				}
			}
			else {
				for(int j = 1; j <= 30 ; j++) {
								counter+=1;
								mondefine= counter%7;
								dayArray[i][j]=mondefine;
							}

			}

				}
	}
	switch (dayArray[x][y]) {
	case 1:
		cout <<"MON";
		break;
	case 2:
		cout <<"TUE";
		break;
	case 3:
		cout <<"WED";
		break;
	case 4:
		cout <<"THU";
		break;
	case 5:
		cout <<"FRI";
		break;
	case 6:
		cout <<"SAT";
		break;
	case 0:
		cout <<"SUN";
		break;
	default:
		cout <<"잘못된값이 들어가있음";
	}

	return 0;
}
