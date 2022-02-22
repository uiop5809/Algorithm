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

int T, N, num, preSum[1001];

int main() {
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> num;
			preSum[i] = preSum[i - 1] + num;
		}

		int m = 0;
		int res = -100000000;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				m = preSum[i] - preSum[j - 1];

				if (res < m) {
					res = m;
				}
			}
		}
		cout << res << "\n";
	}
}