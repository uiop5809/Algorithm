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

//dp[i][j]  i = 자릿수, j = 가장 오른쪽 숫자

int T, n;
long long dp[65][10];

int main() {
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i < 65; i++)
		for (int j = 0; j < 10; j++)
			for (int k = j; k < 10; k++)
				dp[i][j] += dp[i - 1][k];

	cin >> T;
	while (T--) {
		cin >> n;
		long long result = 0;
		for (int i = 0; i <= 9; i++)
			result += dp[n][i];
		cout << result << '\n';
	}
}