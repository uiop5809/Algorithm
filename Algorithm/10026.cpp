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

int N, Rcnt, Gcnt, Bcnt, R1cnt;
char num[101][101];
bool c[101][101];
bool check = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs(int x, int y, char kind) {
	q.push({ x, y });
	c[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (!check && num[nx][ny] == kind && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
			if (check && (num[nx][ny] == kind || num[nx][ny] == 'G') && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (num[i][j] == 'R' && !c[i][j]) {
				bfs(i, j, 'R');
				Rcnt++;
			}
			else if (num[i][j] == 'G' && !c[i][j]) {
				bfs(i, j, 'G');
				Gcnt++;
			}
			else if (num[i][j] == 'B' && !c[i][j]) {
				bfs(i, j, 'B');
				Bcnt++;
			}
		}
	}

	memset(c, 0, sizeof(c));

	check = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((num[i][j] == 'R' || num[i][j] == 'G') && !c[i][j]) {
				bfs(i, j, 'R');
				R1cnt++;
			}
		}
	}
	cout << Rcnt + Gcnt + Bcnt << " " << R1cnt + Bcnt;
}