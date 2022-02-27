#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;

int N, M, money[10001], res = 0;

ll binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			if (money[i] < mid) {
				sum += money[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum <= M) {
			left = mid + 1;
			if (mid > res) {
				res = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	
	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		if (max < money[i]) {
			max = money[i];
		}
	}
	cin >> M;
	cout << binary_search(1, max);
}