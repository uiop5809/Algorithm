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

int T, M, N, K;
int num[51][51];
int c[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1)
				continue;
			if (num[nx][ny] == 1 && c[nx][ny] == 0) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			int x, y;
			cin >> x >> y;
			num[x][y] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (num[i][j] == 1 && c[i][j] == 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		memset(num, 0, sizeof(num));
		memset(c, 0, sizeof(c));
	}
	return 0;
}