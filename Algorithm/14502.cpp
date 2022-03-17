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

int N, M, res = 0;
int num[9][9];
int num_copy[9][9];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector <pair <int, int>> v;

void bfs() {
	queue <pair <int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second });
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (num_copy[nx][ny] == 0) {
				num_copy[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (num_copy[i][j] == 0) cnt++;
		}
	}
	res = max(res, cnt);
}

void wall(int cnt) {
	if (cnt == 3) { // 벽이 3개 됐을 때
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				num_copy[i][j] = num[i][j];
			}
		}
		bfs();
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (num[i][j] == 0) {
				num[i][j] = 1;
				wall(cnt + 1);
				num[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num[i][j];

			if (num[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (num[i][j] == 0) {
				num[i][j] = 1;
				wall(1);
				num[i][j] = 0;
			}
		}
	}
	cout << res;
}