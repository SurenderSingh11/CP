#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int sum, int n) {
	if(sum == 0) {
		return true;
	}
	if(n == 0) {
		return false;
	}

	if(arr[n-1] > sum) {
		return solve(arr, sum, n-1);
	}
	return solve(arr, sum - arr[n-1], n-1) || solve(arr, sum, n-1);
}

int main() {
	int n, sum;
	cin >> n;
	if(n <= 0) {
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