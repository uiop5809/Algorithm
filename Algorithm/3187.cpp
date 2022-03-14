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

int R, C, kx, vx;
char num[251][251];
bool c[251][251];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	int vcnt = 0, kcnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (num[x][y] == 'v') vcnt++;
		if (num[x][y] == 'k') kcnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > R || ny < 1 || ny > C)
				continue;
			if (num[nx][ny] != '#' && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
	if (kcnt > vcnt) {
		vx += vcnt;
	}
	else {
		kx += kcnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	int vcnt = 0, kcnt = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> num[i][j];
			if (num[i][j] == 'v') vcnt++;
			if (num[i][j] == 'k') kcnt++;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (num[i][j] != '#' && !c[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << kcnt - kx << " " << vcnt - vx;
}