#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int sum, int n) {
	int dp[n+1][sum+1];
	for(int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}	
	for(int i = 1; i <= sum; ++i) {
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= sum; ++j) {
			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			if(arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i = sum/2; i >= 0; --i) {
		if(dp[n][i] != 0) {
			return sum - 2*i;
		}
	}
}

int main() {
	int n;
	cin >> n;
	if(n <= 0) {
		exit(0);
	}
	int arr[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int sum = 0;
	for(int i : arr) {
		sum += i;
	}
	cout << solve(arr, sum, n) << endl;
	return 0;
}