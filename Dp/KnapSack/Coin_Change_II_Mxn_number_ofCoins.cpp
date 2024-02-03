#include<bits/stdc++.h>
using namespace std;

int solve(int coins[], int M, int V) 
{ 
    int dp[M+1][V+1];
    for(int i = 0; i <= M; ++i) dp[i][0] = 0;
    for(int i = 1; i <= V; ++i) dp[0][i] = INT_MIN+1;
        
    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= V; ++j) {
            if(coins[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[M][V] <= 0 ? -1 : dp[M][V];
} 

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << solve(arr, n, target);
    return 0;
}