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

long long dp[100001];

long long dynamic(int n) {
	dp[1] = dp[3] = 50001;
	dp[2] = dp[5] = 1;
	dp[4] = 2;

	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
	}
	return dp[n] > 50000 ? -1 : dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << dynamic(n);
}