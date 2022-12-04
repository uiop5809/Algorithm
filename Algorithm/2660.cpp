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

int N, a, b;
int dp[51][51];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
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

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) dp[i][j] = INF;
		}
	}
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dp[a][b] = dp[b][a] = 1;
	}
	floyd();

	int ans[51];
	int point = INF;
	for (int i = 1; i <= N; i++) {
		int max = 0;
		for (int j = 1; j <= N; j++) {
			if (max < dp[i][j]) max = dp[i][j];
		}
		ans[i] = max;         
		point = min(point, ans[i]); 
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (ans[i] == point) cnt++;
	}
	cout << point << " " << cnt << "\n";
	for (int i = 1; i <= N; i++) {
		if (ans[i] == point) cout << i << " ";
	}
}