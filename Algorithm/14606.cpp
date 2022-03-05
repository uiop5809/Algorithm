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

int dp[10];

int dynamic(int n) {
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= 10; i++) {
		if (i % 2 == 0) {
			dp[i] = (i / 2) * (i / 2) + dp[i / 2] + dp[i / 2];
		}
		else {
			dp[i] = (i / 2) * (i / 2 + 1) + dp[i / 2] + dp[i / 2 + 1];
		}
	}
	return dp[n];
}

int main() {
	int N;
	cin >> N;

	cout << dynamic(N);
}