#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int sum, int n) {
	int dp[n+1][sum+1];
	for(int i = 1; i <= sum; ++i) {
		dp[0][i] = INT_MAX-1;
	}
	for(int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= sum; ++j) {
			if(arr[i-1] <= j) {
				dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[M][V] >= INT_MAX-1 ? -1 : dp[M][V];
}

int main() {
	int n;
	cin >> n;
	if(n <= 0)	exit(0);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	cout << solve(arr, sum, n) << endl;
	return 0;
}