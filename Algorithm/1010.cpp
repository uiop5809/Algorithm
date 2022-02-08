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

int dp[30][30];
int combi(int n, int r) {
	if (dp[n][r] > 0)
		return dp[n][r];
	if (n == r || r == 0)
		return 1;
	else {
		dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
		return dp[n][r];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << combi(b, a) << "\n";
	}
	return 0;
}