#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int sum, int n) {
	bool t[n+1][sum+1];
	for(int i = 0; i < n+1; ++i) {
		t[i][0] = true;
	}
	for(int j = 1; j < sum+1; ++j) {
		t[0][j] = false;
	}

	for(int i = 1; i < n+1; ++i) {
		for(int j = 1; j < sum+1; ++j) {
			if(arr[i-1] <= j) {
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			}
			if(arr[i-1] > j) {
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][sum];
}

int main() {
	int n, sum;
	cin >> n;
	if(n <= 0) {
		cout << "Wrong value of n";
		exit(0);
	}
	int arr[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> sum;
	if(sum <= 0) {
		cout << "Wrong value of sum";
		exit(0);
	}
	if(solve(arr, sum, n)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;

}