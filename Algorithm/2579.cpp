#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int T;
int score[301], dp[301];

int dynamic(int T) {
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	dp[3] = max(score[1] + score[3], score[2] + score[3]);

	for (int i = 4; i <= T; i++) {
		dp[i] = max(dp[i - 1]+score[i], dp[i - 2]+score[i]);
	}
	return dp[T];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> score[i];
	}
	cout << dynamic(T);
}