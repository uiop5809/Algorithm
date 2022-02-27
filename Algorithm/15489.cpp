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

int dp[31][31];
int res;

int dynamic(int r, int c, int w) {
	for (int i = 1; i < r + w; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i < r + w; i++) {
		for (int j = 2; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	for (int i = r; i < r + w; i++) {
		for (int j = c; j <= c + i - r; j++) {
			res += dp[i][j];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int R, C, W;
	cin >> R >> C >> W;

	cout << dynamic(R, C, W);
}