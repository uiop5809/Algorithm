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

typedef long long ll;

ll K, N, lan[10001];
ll res = 0;

ll binary_search(ll left, ll right) {
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += lan[i] / mid;
		}
		if (N <= cnt) {
			res = max(res, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	ll max = 0;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (max < lan[i]) {
			max = lan[i];
		}
	}
	cout << binary_search(1, max);
}