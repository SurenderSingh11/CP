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

	int i = m, j = n;
	string str = "";

	while(i > 0 && j > 0) {
		if(x[i-1] == y[j-1]) {
			str.push_back(x[i-1]);
			i--;
			j--;
		}
		else {
				if(t[i-1][j] > t[i][j-1]) {
					str.push_back(x[i-1]);
					i--;
				}
				else if(t[i][j-1] > t[i-1][j]) {
						str.push_back(y[j-1]);
						j--;
					}
		}
	}

	while(i > 0) {
		str.push_back(x[i-1]);
		i--;
	}
	while(j > 0) {
		str.push_back(y[j-1]);
		j--;
	}

	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}