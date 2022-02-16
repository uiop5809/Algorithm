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

int n, k;
int dp[31][31];

int dynamic(int n, int k) {
	for (int i = 0; i < 31; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = 1; j < i + 1; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j];
		}
	}
	return dp[n-1][k-1];
}

int main() {
	cin >> n >> k;
	cout << dynamic(n, k);
}