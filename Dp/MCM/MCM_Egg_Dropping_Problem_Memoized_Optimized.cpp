#include<bits/stdc++.h>
using namespace std;

int static t[10][52];

int solve(int e, int f) {
	if(f == 0 || f == 1) {
		return f;
	}
	if(e == 1) {
		return f;
	}
	if(t[e][f] != -1) {
		return t[e][f];
	}
	int high, low;
	int mn = INT_MAX;
	for(int k = 1; k <= f; ++k) {
		if(t[e-1][k-1] != -1) {
			low = t[e-1][k-1];
		}
		else {
			low = solve(e-1, k-1);
			t[e-1][k-1] = low;
		}
		if(t[e][f-k] != -1) {
			high = t[e][f-k];
		}
		else {
			high = solve(e, f-k);
			t[e][f-k] = high;
		}
		int temp = 1 + max(low, high);
		mn = min(mn, temp);
	}
	return t[e][f] = mn;
}

int main() {
	memset(t, -1, sizeof(t));
	int floors, eggs;
	cin >> floors >> eggs;
	cout << solve(floors, eggs) << endl;
	return 0;
}