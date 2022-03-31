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

int N;
int dp[101][101];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][k] && dp[k][j]) {
					dp[i][j] = 1;
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
			cin >> dp[i][j];
		}
	}

	floyd();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}