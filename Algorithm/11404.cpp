#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int n, m, a, b, c;
int dp[101][101];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dp[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
		// 시작과 도착 연결 노선은 1개가 아닐 수도 있음
	}

	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (dp[i][j] != INF ? dp[i][j] : 0) << " ";
		}
		cout << "\n";
	}
}