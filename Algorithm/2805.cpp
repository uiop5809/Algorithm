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

ll N, M, res = 0;
ll tree[1000001];

ll binary_search(ll left, ll right) {
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll tree_length = 0;

		for (int i = 0; i < N; i++) {
			if (tree[i] - mid > 0) {
				tree_length += tree[i] - mid;
			}
		}
		if (tree_length >= M) {
			if (res < mid) {
				res = mid;
			}
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
	cin.tie(NULL); cout.tie(NULL);

	ll max = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (max < tree[i]) {
			max = tree[i];
		}
	}
	cout << binary_search(1, max);
}