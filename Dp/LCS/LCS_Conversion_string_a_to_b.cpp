#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int main() {
	string x, y;
	cin >> x >> y;

	int m = x.length();
	int n = y.length();

	for(int i = 1; i < m+1; ++i) {
		for(int j = 1; j < n+1; ++j) {
			if(x[i-1] == y[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	}

	cout << "Deletion :- " << m-t[m][n] << endl;
	cout << "Insertion :- " << n-t[m][n];
	return 0;
}