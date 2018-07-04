//============================================================================
// Name        : 2016_11_04_2178.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

void printMatrix(int** mat, int raw, int col) {
	for (int i = 1; i <= raw; i++) {
		for (int j = 1; j <= col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int raw = 0;
	int col = 0;
	cin >> raw >> col;

	//making bagic matrix
	int** matMap = new int*[raw + 1];
	for (int i = 1; i <= raw; i++) {
		matMap[i] = new int[col + 1];
		memset(matMap[i], 0, sizeof(int) * (col + 1));
	}

	//making matrix and space between numbers
	string temp;
	string critera = "0";
	for (int i = 1; i <= raw; i++) {
		cin >> temp;
		for (int j = 1; j <= col; j++)
			matMap[i][j] = (int) temp[j - 1] - (int) critera[0];
	}


// making path matrix
	int** matMapRm = new int*[raw + 1];
	for (int i = 1; i <= raw; i++) {
		matMapRm[i] = new int[col + 1];
		memset(matMapRm[i], 0, sizeof(int) * (col + 1));
	}
	for (int i = 1; i <= raw; i++)
		memcpy(matMapRm[i], matMap[i], sizeof(int) * (col + 1));
	//처음에 들렸다고 가정해야하기 때문에
	matMapRm[1][1] = 0;


	//bfs
	int Pair[3] = { 1, 1, 1 };
	int sortestDis = 0;
	queue<int*> container;
	container.push(Pair);
	while ((container.empty() != 1)) {

		int x, y, dist;

		x = container.front()[0];
		y = container.front()[1];
		dist = container.front()[2];

		if((x == 1) && (y == 4)) {
			cout<<"here here"<<endl;
		}

		if ((x == raw) && (y == col)) {
			sortestDis = dist;
			cout << "here is end" << endl;
			break;
		}

		//upside
		if (((x - 1) > 0) && (matMap[x - 1][y] == 1)) {
			int temp[3];
			temp[0] = x - 1;
			temp[1] = y;
			temp[2] = dist + 1;
			container.push(temp);
			matMapRm[x - 1][y] = 0;

		}
		//down side
		if (((x + 1) <= raw) && (matMap[x + 1][y] == 1)) {
			int temp[3];
			temp[0] = x + 1;
			temp[1] = y;
			temp[2] = dist + 1;
			container.push(temp);
			matMapRm[x + 1][y] = 0;
		}
		//left side
		if (((y - 1) > 0) && (matMap[x][y - 1] == 1)) {
			int temp[3];
			temp[0] = x;
			temp[1] = y - 1;
			temp[2] = dist + 1;
			container.push(temp);
			matMapRm[x][y - 1] = 0;
		}
		//right side
		if (((y + 1) <= col) && (matMap[x][y + 1] == 1)) {
			int temp[3];
			temp[0] = x;
			temp[1] = y + 1;
			temp[2] = dist + 1;
			container.push(temp);
			matMapRm[x][y + 1] = 0;
		}

		container.pop();
	}
	if(sortestDis != 0)
		cout << sortestDis << endl;

}
