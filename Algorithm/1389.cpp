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

int N, M, A, B;
int dp[101][101];
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

	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) dp[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		dp[A][B] = 1;
		dp[B][A] = 1;
	}
	floyd();

	int sum = 0, min = INF;
	vector <pair <int, int>> res; // sum, index
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum += dp[i][j];
		}
		res.push_back({sum, i});
		sum = 0;
	}

	sort(res.begin(), res.end());
	cout << res[0].second;
}