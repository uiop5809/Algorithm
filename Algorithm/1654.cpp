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

int k, n;
long long num[10001];

bool possible(long long len) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += num[i] / len;
	}

	if (cnt >= n) {
		return true;
	}
	return false;
}

int main() {
	cin >> k >> n;

	long long right = 0;
	long long left = 1;

	for (int i = 0; i < k; i++) {
		cin >> num[i];
		right = max(right, num[i]);
	}
	
	long long result = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (possible(mid)) {
			if (result < mid) {
				result = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << "\n";
}