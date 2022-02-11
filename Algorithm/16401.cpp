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

ll M, N, ans;
ll snack[1000001];

ll binary_search(ll left, ll right, ll M) {
	while (left <= right) {
		ll cnt = 0;
		ll mid = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			cnt += snack[i] / mid;
		}
		if (cnt >= M) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	ll smax = 0;

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> snack[i];
	}
	sort(snack, snack + N);
	cout << binary_search(1, snack[N-1], M);
}