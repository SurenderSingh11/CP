#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; //dp globally declared so initialization alreay at zero

int main() {
	string x, y;
	cin >> x >> y;
	int m = x.length();
	int n = y.length();

	//creating a dp table to store size of lcs
	for(int i = 1; i < m+1; ++i) {
		for(int j = 1; j < n+1; ++j) {
			if(x[i-1] == y[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	}

	//bactracking the dp table from the end to print the lcs
	int i = m, j = n;
	string str = "";
	while(i > 0 && j > 0) {
		if(x[i-1] == y[j-1]) {
			str.push_back(x[i-1]);
			i--;
			j--;
		}
		else {
			if(t[i][j-1] > t[i-1][j])
				j--;
			else 
				i--;
		}
	}

	//reverse the string as we were backtracking the lcs
	reverse(str.begin(), str.end()); 
	cout << str ;

	return 0;
}