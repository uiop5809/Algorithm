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

int N, Q, num[300001];
int preSum[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	sort(num, num + N + 1);

	for (int i = 1; i <= N; i++) {
		preSum[i] = preSum[i - 1] + num[i];
	}

	int x, y;
	while (Q--) {
		cin >> x >> y;
		cout << preSum[y] - preSum[x - 1] << "\n";
	}
}