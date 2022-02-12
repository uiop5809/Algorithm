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

//dp[i][0] : 1로 시작하고, 1보다 작거나 같은 수 경우
//dp[i][1] : 2로 시작하고, 2보다 작거나 같은 수 경우
//dp[i][2] : 3로 시작하고, 3보다 작거나 같은 수 경우

int T, n;
int dp[10004][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i < 10001; i++) {
		dp[i][0] = 1;
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}

	while (T--) {
		cin >> n;
		cout << dp[n][0] + dp[n][1] + dp[n][2] << "\n";
	}
}