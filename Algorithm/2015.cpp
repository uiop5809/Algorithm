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

int N, K, num;
long long preSum[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		preSum[i] = preSum[i - 1] + num;
	}

	vector <int> v;
	for (int i = 0; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			v.push_back(preSum[i + j] - preSum[i]);
		}
	}
	
	long long cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == K) {
			cnt++;
		}
	}

	cout << cnt;
}