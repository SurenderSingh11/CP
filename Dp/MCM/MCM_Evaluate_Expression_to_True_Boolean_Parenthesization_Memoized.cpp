#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool istrue) {
	if(i > j) {
		return false;
	}
	if(i == j) {
		if(istrue == true) 
			return s[i] == 'T';
		else 
			return s[i] == 'F';
	}

	string temp = to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.append(to_string(istrue));

	if(mp.find(temp) != mp.end()) 
		return mp[temp];

	int ans = 0;
	for(int k = i+1; k < j; k += 2) {
		int lT = solve(s, i, k-1, true);
		int lF = solve(s, i, k-1, false);
		int rT = solve(s, k+1, j, true);
		int rF = solve(s, k+1, j, false);

		if(s[k] == '&') {
			if(istrue == true) 
				ans += lT * rT;
			else 
				ans += lT * rF + lF * rF + lF * rT;
		}
		else if(s[k] ==  '|') {
			if(istrue == true) 
				ans += lT * rF + lT * rT + lF * rT;
			else 
				ans += lF * rF;
		}
		else if (s[k] == '^') {
			if(istrue == true) 
				ans += lT * rF + lF * rT;
			else 
				ans += lT * rT + lF * rF;
		}
	}

	return mp[temp] = ans;
}

int main() {
	mp.clear();
	string s;
	cin >> s;
	int i = 0, j = s.length()-1;
	cout << solve(s,i, j, true) << endl;
	return 0;
}