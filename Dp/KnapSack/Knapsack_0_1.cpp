#include<bits/stdc++.h>
using namespace std;

int static t[102][1002];

int knapsack(int wt[], int val[], int W, int n) {
	if(n == 0 && W == 0) {
		return 0;
	}
	if(t[n][W] != -1) {
		return t[n][W];
	}
	if(wt[n-1] <= W) {
		return t[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
	}
	else if(wt[n-1] > W) {
		return t[n][W] = knapsack(wt, val, W, n-1);
	}
}

 int main() {
	memset(t,-1, sizeof(t));
    int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    cout << knapsack(weight, profit, W, n); 
    return 0; 
 }