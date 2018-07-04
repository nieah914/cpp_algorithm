//============================================================================
// Name        : q2194.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
	int row,col,a,b,k;					//필요 변수 선언
	cin >> row >> col >> a >> b >> k;
	char** matrix = new char*[row+1];		//맵 선언
	int* blockX = new int[k];
	int* blockY = new int[k];

	memset(blockX,0,sizeof(int)*k);
	memset(blockY,0,sizeof(int)*k);



	for(int i = 0 ; i < k ; i ++) {
		cin >> blockX[i] >> blockY[i];
	}

	int xX,xY;
	int yX,yY;
	cin >> xX >> xY >> yX >> yY;



	for(int i = 0 ; i < row + 1 ; i ++ ) {
		matrix[i] = new char[col+1];
		memset(matrix[i], '0', sizeof(char) * (col+1));
	}

	for(int i = 0 ; i < k ; i++) {
		matrix[blockX[i]][blockY[i]] = '1';
	}
	for(int i = 0 ; i < a ; i++) {
		for(int j = 0 ; j < b ; j++) {
			matrix[xX+i][xY+j] = '*';
			matrix[yX+i][yY+j] = '*';
		}
	}




	for( int i = 1 ; i <= row ; i ++) {
		for ( int j = 1 ; j <= col ; j++) {
			cout << matrix[i][j]<<' ';
		}
		cout << endl;
	}


	return 0;
}
