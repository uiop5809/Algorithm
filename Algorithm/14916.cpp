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

long long dp[1000001];

long long dynamic(int n) {
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << dynamic(n);
}