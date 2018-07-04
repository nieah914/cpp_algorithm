//============================================================================
// Name        : 2016_11_16_1620.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;


class PkData {
public :
	int pknum;
	char* pkName;
	PkData() {
		pknum = 0;
		pkName = new char[100];
	}
	bool operator<(const PkData &t) const {
		return (*pkName < *t.pkName);
	}

};
vector<PkData> pk;
int binarysearchtree(int& begin, int& mid, int& end, char* pkName);

int main() {
	int pktNum = 0;
	int qNum = 0;
	cin >> pktNum >> qNum;

	//½ÇÇè 1
	char** pkmName = new char*[pktNum+1];
	for(int i = 1; i <= pktNum ; i++) {
		pkmName[i] = new char[100];
		cin >> pkmName[i];
	}

	for(int i = 1; i <= pktNum ; i++) {
		PkData pktemp;
		strcpy(pktemp.pkName,pkmName[i]);
		pktemp.pknum = i;
		pk.push_back(pktemp);
		//cout<< pkmName[i] <<endl;
	}
	sort(pk.begin(),pk.end());


	for(int i = 1; i <= qNum ; i++) {
		char* question = new char[100];
		cin >> question;
		if(('A'<=question[0]) && (question[0]<='Z')) {
			int zero = 0;
			int midNum = pktNum/2;
			cout<<binarysearchtree(zero,midNum,pktNum,question)<<endl;
		}
		else {
			int temp;
			temp = atoi(question);
			cout<<pkmName[temp]<<endl;
		}

	}

}

int binarysearchtree(int& begin, int& mid, int& end, char* pkName) {

	if (begin > end) {
		cout << "here4" << endl;
		return -1;
	}

	if (strcmp(pk[mid].pkName, pkName) == 0) {
		cout << "here is " << pkName << endl;
		cout << "here1" << endl;
		cout << pkName << "num is " << pk[mid].pknum << endl;
		return pk[mid].pknum;
	}
	else if (pk[mid].pkName > pkName) {
		begin = mid+1;
		mid = (begin+end)/2;
		cout<<"here2"<<endl;
		return binarysearchtree(begin,mid,end,pkName);
	}
	else if(pk[mid].pkName < pkName) {
		end = mid-1;
		mid = (begin+end)/2;
		cout<<"here3"<<endl;
		return binarysearchtree(begin,mid,end,pkName);
	}

}
