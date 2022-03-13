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

int N, M;
int num[301][301];
bool c[301][301];

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

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (num[nx][ny] == 0 && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
			else if(num[nx][ny] > 0){
				num[nx][ny]--;

				if (num[nx][ny] == 0) {
					c[nx][ny] = 1;
				}
			}
		}
	}
}

void bfs1(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (num[nx][ny] > 0 && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
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
		}
	}

	int res = 0;
	while (1) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (num[i][j] > 0 && !c[i][j]) {
					bfs1(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2) {
			cout << res;
			break;
		}
		else if (cnt == 0) {
			cout << 0;
			break;
		}
		memset(c, 0, sizeof(c));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (num[i][j] == 0 && !c[i][j]) {
					bfs(i, j);
				}
			}
		}
		res++;
		memset(c, 0, sizeof(c));
	}
}