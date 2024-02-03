#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];

bool solve(int arr[], int sum, int n) {
	if(sum == 0) {
		return true;
	}
	if(n == 0) {
		return false;
	}

	if(t[n][sum] != -1) {
		return t[n][sum];
	}

	if(arr[n-1] > sum) {
		return t[n][sum] = solve(arr, sum, n-1);
	}
	return  t[n][sum] = solve(arr, sum - arr[n-1], n-1) || solve(arr, sum, n-1);
}

int main() {
	memset(t, -1, sizeof(t));
	int n, sum;
	cin >> n;
	if(n <= 0) {
		cout << "Wrong value";
		exit(0);
	}
	int arr[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> sum;
	if(solve(arr, sum, n)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;

}