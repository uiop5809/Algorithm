#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int T, num;
int dp[100001];

int fibo0(int n) {
	dp[0] = 1;
	dp[1] = 0;
	for (int i = 2;i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int fibo1(int n) {
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2;i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> num;
		cout << fibo0(num) << " " << fibo1(num) << "\n";
	}
}