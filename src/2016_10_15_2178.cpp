//============================================================================
// Name        : 2016_10_15_2178.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct st{
	int x_ ;
	int y_ ;
	int l_ ;
};

int BFS(int** matrix,int maxX, int maxY ) {
	int x, y;
	x = 1;
	y = 1;
	st nextXYL;
	st destinXYL;


	queue<st> containerXY;
	nextXYL.x_ = 1;
	nextXYL.y_ = 1;
	nextXYL.l_ = 0;
	containerXY.push(nextXYL);

	while (containerXY.size() != 0) {
		matrix[x][y] = 0;
		nextXYL = containerXY.front();

		if ((matrix[x + 1][y] == 1) && (x<maxX)) {
			nextXYL.x_ = x+1;
			nextXYL.y_ = y;
			nextXYL.l_ += 1;
			x +=1;
			containerXY.push(nextXYL);
		}
		else if ((matrix[x - 1][y] == 1) && (x > 1)){
			nextXYL.x_ = x-1;
			nextXYL.y_ = y;
			nextXYL.l_ += 1;
			x-=1;
			containerXY.push(nextXYL);

		}
		else if ((matrix[x][y + 1] == 1) && (y<maxY)){
			nextXYL.x_ = x;
			nextXYL.y_ = y+1;
			nextXYL.l_ += 1;
			y+=1;
			containerXY.push(nextXYL);
		}
		else if ((matrix[x][y - 1] == 1) && (y >1)){
			nextXYL.x_ = x;
			nextXYL.y_ = y-1;
			nextXYL.l_ += 1;
			y-=1;
			containerXY.push(nextXYL);
		}
		destinXYL=containerXY.front();
		containerXY.pop();
		cout<<"containerXY"<<containerXY.size()<<endl;

	}

}

void printMatrix(int**matrix, int x, int y) {
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {
	string whaleMap;
	string one = "1 ";
	string zero = "0 ";

	int x, y;
	cin >> x >> y;

	// 가능한 길목의 여부 메트릭스 초기화
	int**matrix = new int*[x + 1];
	for (int i = 1; i <= x; i++) {
		matrix[i] = new int[y + 1];
		memset(matrix[i], 0, sizeof(int) * (y + 1));
	}

	// 해당 배열까지 이동시 들어가는 경로 카운터 메트릭스
	int**counterMatrix = new int*[x + 1];
	for (int i = 1; i <= x; i++) {
		counterMatrix[i] = new int[y + 1];
		memset(counterMatrix[i], 0, sizeof(int) * (y + 1));
	}

	int* visit = new int[x * y + 1];
	memset(visit, 0, sizeof(int) * (x * y + 1));

	//변환 시키는것
	for (int i = 1; i <= x; i++) {
		cin >> whaleMap;
		for (int j = 0; j < y; j++) {
			if (whaleMap[j] == one[0])
				matrix[i][j + 1] = 1;
			else if (whaleMap[i] == zero[0]) {
				matrix[i][j + 1] = 0;

			}
		}
	}

	BFS(matrix,x,y);


	return 0;

}
