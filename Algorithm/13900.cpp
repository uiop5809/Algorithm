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

int N, num[100001];
long long sum = 0;
long long preSum[100001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		preSum[i] = preSum[i - 1] + num[i];
	}

	for (int i = 1; i < N; i++) {
		sum += num[i] * (preSum[N] - preSum[i]);
	}
	cout << sum;
}