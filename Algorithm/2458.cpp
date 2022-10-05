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

int N, M, a, b;
int num[501][501];
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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(i != j) num[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		num[a][b] = 1;
	}
	floyd();

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			// i보다 큰 사람이 존재 || i보다 작은 사람이 존재
			if (num[i][j] != INF || num[j][i] != INF) {
				cnt++;
			}
		}
		if (cnt == N - 1) res++; // 자신을 제외한 모든 정점과 연결
	}
	cout << res;
}