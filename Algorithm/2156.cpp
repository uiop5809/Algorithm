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

int p[10001];
int dp[10001] = { 0 };

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	dp[1] = p[1];
	dp[2] = p[1] + p[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = p[i] + max(dp[i - 2], p[i - 1] + dp[i - 3]);
		//n-1��°�� ���Ͽ� n��° ���� ���ô� ��
		dp[i] = max(dp[i], dp[i - 1]);
		//�� ���ô� ��
	}
	cout << dp[n];
}