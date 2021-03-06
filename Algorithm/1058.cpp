#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N;
char c[51][51];
int num[51][51];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (num[i][j] > num[i][k] + num[k][j]) {
					num[i][j] = num[i][k] + num[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) num[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'Y') num[i][j] = 1;
		}
	}
	floyd();

	int max = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j && num[i][j] <= 2) {
				cnt++;
			}
		}
		if (max < cnt) max = cnt;
	}
	cout << max;
}