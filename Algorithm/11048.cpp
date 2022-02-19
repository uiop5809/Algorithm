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

int N, M;
int dp[1001][1001];

int dynamic(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1;j <= M; j++) {
			cin >> dp[i][j];
		}
	}
	cout << dynamic(N, M);
}