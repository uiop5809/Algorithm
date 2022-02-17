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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	long long n[100001];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	sort(n, n + N);
	
	int cnt = 1, max = 0;
	long long ans = n[0];
	for (int i = 0; i < N - 1; i++) {
		if (n[i] == n[i + 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (max < cnt) {
			max = cnt;
			ans = n[i];
		}
	}
	cout << ans;
}