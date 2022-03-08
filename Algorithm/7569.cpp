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

int M, N, H;
int num[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue <pair <pair <int, int>, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (x < 1 || y < 1 || z < 1 || nx > N || ny > M || nz > H)
				continue;
			if (num[nz][nx][ny] == 0) {
				num[nz][nx][ny] += num[z][x][y] + 1;
				q.push({ { nx, ny }, nz });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> H;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> num[k][i][j];
				if (num[k][i][j] == 1) {
					q.push({ { i, j }, k });
				}
			}
		}
	}
	bfs();

	int day = 0;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (num[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				if (day < num[k][i][j]) {
					day = num[k][i][j];
				}
			}
		}
	}
	cout << day - 1;
}