#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, result;
int num[21][21];
int res[21][21];

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k == i || k == j) continue;
				else if (num[i][j] > num[i][k] + num[k][j]) {
					result = -1;
					return;
				}
				else if (num[i][j] == num[i][k] + num[k][j]) {
					res[i][j] = 0;
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
			cin >> num[i][j];
			res[i][j] = num[i][j];
		}
	}
	floyd();

	if (result != -1) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				sum += res[i][j];
			}
		}
		cout << sum / 2;
	}
	else cout << result;
}