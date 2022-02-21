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

int N;
int a[2001], dp[2001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[i] < a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sum = max(sum, dp[i]);
	}

	cout << N - sum;
}