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

int T;
int n[100001],dp[100001];

int dynamic(int T) {
	dp[1] = n[1];
	int sum = dp[1];

	for (int i = 2; i <= T; i++) {
		dp[i] = max(dp[i - 1] + n[i], n[i]);
		sum = max(sum, dp[i]);
	}
	return sum;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n[i];
	}
	cout << dynamic(T);
}