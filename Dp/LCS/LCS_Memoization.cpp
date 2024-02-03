#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int lcs(string x, string y, int m, int n) {
	if(n == 0 || m == 0) {
		return 0;
	}
	if(t[m][n] != -1) {
		return t[m][n];
	}
	if(x[m-1] == y[n-1]) {
		return t[m][n] = 1+lcs(x, y, m-1, n-1);
	}
	else{
		return t[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
	}
}

int main() {
	memset(t, -1, sizeof(t));
	string x, y;
	cin >> x >> y;
	int ans = lcs(x, y, x.length(), y.length());
	cout << ans << endl;

	return 0;
}