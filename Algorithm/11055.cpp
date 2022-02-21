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

int main() {
	int N, a[1001];
	int dp[1001];
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = a[i];
		for (int j = 1; j <= i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + a[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
		sum = max(sum, dp[i]);
	}
	cout << sum;
}