//============================================================================
// Name        : 2016_10_12_2579.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;

int arr[302];
int dp[302];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];
	cout << dp[-1] <<endl;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i- 2] + arr[i], dp[i-3] +arr[i-1]+ arr[i]);
	}
	cout << dp[n];

}
/*#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int LayerValue[301] = { 0, };
	int LayerNum = 0;
	int DP[301] = { 0, };
	int result = 0;
	int counter = 0;

	cin >> LayerNum;
	for (int i = 1; i <= LayerNum; i++) {
		cin >> LayerValue[i];
	}


	for (int i = 1; i <= LayerNum; i++) {
		if(counter < 2) {
			DP[i] = max(DP[i], DP[i-1] +LayerValue[i]);
			counter += 1;
		}
		else counter = 0;
		if(i!=1)
			DP[i] = max(DP[i], DP[i-2] +LayerValue[i]);
		result = max(result,DP[i]);
	}

	cout <<result<< endl; // prints !!!Hello World!!!
	*/
	/*
	int LayerValue[301] = { 0, };
	int LayerNum = 0;
	int DP[301][2] = { 0, };

	cin >> LayerNum;
	for (int i = 1; i <= LayerNum; i++) {
		cin >> LayerValue[i];
	}

	DP[i][1] = DP[i-3][1] + LayerValue[i-1] + LayerValue[i];
	DP[i][1] = DP[i-3][1] + LayerValue[i-2] + LayerValue[i];

	DP[i][1] = DP[i-2][1] + LayerValue[i];
	DP[i][2] = DP[i-2][1] + LayerValue[i];

	return 0;
}
*/
