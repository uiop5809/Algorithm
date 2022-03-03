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

long long n, m, num, res;
long long preSum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		preSum[i] = preSum[i - 1] + num;
	}

	long long max = 0;
	for (int i = m; i <= n; i++) {
		res = preSum[i] - preSum[i - m];
		
		if (max < res) {
			max = res;
		}
	}
	cout << max;
}