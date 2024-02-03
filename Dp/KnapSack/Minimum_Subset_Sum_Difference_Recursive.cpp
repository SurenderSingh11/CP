#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sumCalc, int sum) {
	if(n == 0) return abs(sum - 2 * sumCalc);

	return min(solve(arr, n-1, sumCalc + arr[n-1], sum), solve(arr, n-1, sumCalc, sum));
}

int main(){
	int n;
	cin >> n;
	if(n <= 0) exit(0);
	int arr[n], sum = 0;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	for(int i : arr) sum += i;
	cout << solve(arr, n, 0, sum) << endl;
	return 0;
}