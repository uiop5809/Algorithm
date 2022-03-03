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

int N, M, res;
int num[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N;i++) {
		cin >> num[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			res += num[j];

			if (res == M) {
				cnt++;
				res = 0;
				break;
			}
		}
		if (res != 0) {
			res = 0;
		}
	}
	cout << cnt;
}

//투 포인터 방식
int N, M;
int num[10001];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int start = 0, end = 0;
	int sum = num[0];

	int cnt = 0;
	while (start <= end && end < N) {
		if (sum < M) {
			sum += num[++end];
		}
		else if (sum == M) {
			cnt++;
			sum += num[++end];
		}
		else if (sum > M) {
			sum -= num[start++];

			if (start > end) {
				end = start;
				sum = num[start];
			}
		}
	}
	cout << cnt;
}