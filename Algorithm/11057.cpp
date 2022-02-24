#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int dp[1001][10];

int dynamic(int n) {
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}
	return sum % 10007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;

	cin >> N;
	cout << dynamic(N);
}