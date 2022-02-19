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

long long dp[81];
long long res[81];
int N;

long long dynamic(int N) {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	res[1] = 4;
	for (int i = 2; i <= N; i++) {
		res[i] = res[i - 1] + dp[i] * 2;
	}
	return res[N];
}

int main() {
	cin >> N;
	cout << dynamic(N);
}