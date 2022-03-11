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

int N, M, res, t;
int num[101][101];
bool c[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

bool bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;
	t++;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (!c[nx][ny]) {
				if (num[nx][ny] == 0) {
					q.push({ nx, ny });
				}
				else { // num[nx][ny] == 1
					num[nx][ny] = 0;
					cnt++;
				}
				c[nx][ny] = 1;
			}
		}
	}
	if (cnt == 0) {
		cout << --t << "\n" << res;
		return true;
	}
	else {
		res = cnt;
		return false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num[i][j];
		}
	}
	while (1) {
		if (bfs(1, 1)) break;
		memset(c, 0, sizeof(c));
	}
}