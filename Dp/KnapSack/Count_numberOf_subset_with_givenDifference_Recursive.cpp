#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int sum, int n) {
	if(sum == 0)	return 1;
	if(n == 0)		return 0;
 
	if(arr[n-1] > sum ) {
		return solve(arr, sum, n-1);
	}
	if(arr[n-1] <= sum) {
		return solve(arr, sum, n-1) + solve(arr, sum - arr[n-1], n-1);
	}
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