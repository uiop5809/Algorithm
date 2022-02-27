#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int n[1001], cnt[1001];

int main() {
	int L, N, max1 = 0, max2 = 0, res1, res2;
	cin >> L >> N;

	for (int i = 1; i <= N; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		for (int j = n1; j <= n2; j++) {
			if (n[j] == 0) {
				n[j] = i;
				cnt[i]++;
			}
		}

		int sub = n2 - n1;
		if (sub > max1) {
			max1 = sub;
			res1 = i;
		}
		if (cnt[i] > max2) {
			max2 = cnt[i];
			res2 = i;
		}
	}

	cout << res1 << "\n" << res2;
}