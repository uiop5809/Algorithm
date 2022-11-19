#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int M, N, res = -1;
int dp[2001][2001];
int num[2001][2001];

void dynamic() {
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			int temp = 0;
			if (i != 0) {
				temp = dp[j][i - 1];
				if (j != 0) temp = max(temp, dp[j - 1][i - 1]);
				if (j < N - 1) temp = max(temp, dp[j + 1][i - 1]);
				dp[i][j] += temp;
			}
			res = max(res, temp);
		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &num[i][j]);
			dp[i][j] = num[i][j];
		}
	}
	dynamic();
}