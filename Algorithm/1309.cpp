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

int dp[1000001];
int main() {
	int N;

	dp[0] = 1;
	dp[1] = 3;

	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	cout << dp[N];
}