#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int main() {
	string x, y;
	cin >> x >> y;
	int m = x.length();
	int n = y.length();
	int ans = INT_MIN;

	for(int i = 1; i < m+1; ++i) {
		for(int j = 1; j < n+1; ++j) {
			if(x[i-1] == y[j-1]) {
				t[i][j] = 1 + t[i-1][j-1];
				ans = max(ans, t[i][j]);
			}
			else
				t[i][j] = 0;
		}
	}

	cout << ans;

	return 0;
}



//Recursive Approach
// int ans(string s1, string s2, int n, int m, int len){

//     if (n == 0 || m == 0)
//         return len;

//     if (s1[n - 1] == s2[m - 1])
//         len = ans(s1, s2, n - 1, m - 1, len + 1);

//     int len1 = ans(s1, s2, n - 1, m, 0);
//     int len2 = ans(s1, s2, n, m - 1, 0);
//     len = max({len, len1, len2});
    
//     return len;
// }








