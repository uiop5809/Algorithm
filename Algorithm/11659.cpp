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

int N, M, num;
int x, y, preSum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		preSum[i] = preSum[i - 1] + num;
	}

	for(int i = 0; i < M; i++){
		cin >> x >> y;

		if (x == 0) {
			cout << preSum[y] << "\n";
		}
		else {
			cout << preSum[y] - preSum[x - 1] << "\n";
		}
	}
}