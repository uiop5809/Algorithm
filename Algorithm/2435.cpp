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

int N, K, num, m;
int preSum[101];

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		preSum[i] = preSum[i - 1] + num;
	}

	int max = -100000000;
	for (int i = 0; i <= N - K; i++) {
		m = preSum[K + i] - preSum[i];

		if (max < m) {
			max = m;
		}
	}
	cout << max;
}