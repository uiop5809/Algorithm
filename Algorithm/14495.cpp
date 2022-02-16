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

long long n, dp[117];

long long dynamic(long long n) {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	return dp[n];
}

int main() {
	cin >> n;
	cout << dynamic(n);
}