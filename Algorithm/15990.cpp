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

#define MOD 1000000009;

// dp[n][i]는 마지막에 오는 수가 i일 때,
// 1, 2, 3의 합으로 정수 n을 만드는 경우의 수

int T, num;
long long dp[100001][4];

long long dynamic(int n) {
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
	return (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> num;
		cout << dynamic(num) << "\n";
	}
}