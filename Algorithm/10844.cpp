#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

#define MOD 1000000000;

int dp[101][10];

int dynamic(int n) {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= MOD;
		}
	}

	int res = 0;
	for (int i = 0; i < 10; i++) {
		res = (res + dp[n][i]) % MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	cout << dynamic(N);
}