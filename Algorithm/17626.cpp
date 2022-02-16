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

int n;
int dp[50001];

int main() {
	cin >> n;

	dp[1] = 1;
	for (int i = 1; i <= n; i++){
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++){
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n];
}