#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int main() {
	string x;
	cin >> x;

	int n = x.length();

	for(int i = 1; i < n+1; ++i) {
		for(int j = 1; j < n+1; ++j) {
			if(x[i-1] == x[j-1] && i != j) 
				t[i][j] = 1 + t[i-1][j-1];
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	}

	cout << t[n][n] << endl;

	return 0;
}