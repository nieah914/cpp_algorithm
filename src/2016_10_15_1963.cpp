//============================================================================
// Name        : 2016_10_15_1963.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <queue>
//#include <stdlib.h>
using namespace std;

void BFS(int*visit, int v, int inputMax, int** matrix) {
	visit[v] = 1; // 정점 방문을 표시
	cout<<v<<"에서 시작"<<endl;
	queue <int> container;

	container.push(v);
	while(container.size() > 0) { // queue가 텅텅 비면 종료
		v = container.front();
		cout <<"v = "<<v<<endl;
		for(int i = 1; i <= inputMax ; i++) { // v와 연결되어있는 모든값을 서치
			if((matrix[v][i] == 1)&&(visit[i] == 0)) {
				container.push(i); // v와 연결된 얘들을 queue에 집어넣음
				cout<<v<<"에서"<<i<<"로 이동"<<endl;
				visit[i] = 1; //정점 방문을 표시
			}
		}
		container.pop(); //queue의 제일 정점을 들고 나옴

	}



}

int main() {
	int vertaxNum;
	int startNum;
	int v1,v2;

	cin >> vertaxNum;
	cin >> startNum;

	int* visit = new int[vertaxNum+1];
	memset(visit,0,sizeof(int)*(vertaxNum+1));
	int** matrix = new int*[vertaxNum+1];

	for(int i = 1; i <= vertaxNum ; i++) {
		matrix[i] = new int[vertaxNum+1];
		memset(matrix[i],0,sizeof(int)*(vertaxNum+1));
	}

	while (1) {
		cin >>v1 >> v2;
		if (v1 == -1 && v2 == -1)
			break;
		matrix[v1][v2] = matrix[v2][v1] = 1;
	}

	BFS(visit,startNum,vertaxNum,matrix);

	delete matrix;
	return 0;

}

