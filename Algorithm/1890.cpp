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

int num[101][101];
long long dp[101][101] = { 0 };

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int jump = num[i][j];
			if (i != N - 1 && i + jump < N) {
				dp[i + jump][j] += dp[i][j];
			}
			if (j != N - 1 && j + jump < N) {
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1];
}