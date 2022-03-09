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

int N;
int num[101][101];
bool c[101][101];

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

		for (int i = 0; i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (!c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int numMax = 0, numMin = 101;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
			numMax = max(numMax, num[i][j]);
			numMin = min(numMin, num[i][j]);
		}
	}

	int res = 1;
	while (numMin <= numMax) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (num[i][j] < numMin) {
					c[i][j] = 1;
				}
			}
		}
		numMin++;

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!c[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (res < cnt) {
			res = cnt;
		}
		memset(c, 0, sizeof(c));
	}
	cout << res;
}