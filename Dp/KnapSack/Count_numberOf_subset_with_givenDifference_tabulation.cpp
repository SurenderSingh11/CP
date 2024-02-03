#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int sum, int n) {
	int dp[n+1][sum+1];
	for(int i = 0; i <= n; ++i)	dp[i][0] = 1;
	for(int i = 1; i <= sum; ++i) dp[0][i] = 0;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= sum; ++j) {
			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
			}
			if(arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int n;
	cin >> n;
	if(n <= 0)	exit(0);

	int arr[n], sum = 0;
	for(int i = 0; i < n; ++i)	cin >> arr[i];
	for(int i : arr)  sum += i;

	int diff, subset = 0;
	cin >> diff;

	subset = (sum + diff)/2;

	cout << solve(arr, subset, n) << endl;
	return 0;
}