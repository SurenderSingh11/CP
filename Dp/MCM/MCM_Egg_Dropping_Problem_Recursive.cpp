#include<bits/stdc++.h>
using namespace std;

int solve(int e, int f) {
	if(f == 0 || f == 1) {
		return f;
	}
	if(e == 1) {
		return f;
	}
	int mn = INT_MAX;
	for(int k = 1; k <= f; ++k) {
		int temp = 1 + max(solve(e-1, k), solve(e, f-k));
		mn = min(mn, temp);
	}
	return mn;
}

int main() {
	int floors, eggs;
	cin >> floors >> eggs;
	cout << solve(floors, eggs) << endl;
	return 0;
}