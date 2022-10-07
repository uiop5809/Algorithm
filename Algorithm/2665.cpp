#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int n;
int num[51][51];
bool dist[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs() {
	q.push({ 1, 1 });
	dist[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > n)
				continue;
			if (num[nx][ny] == 1 && !dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
			else if(num[nx][ny] == 0 && !dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				num[nx][ny] = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &num[i][j]);
		}
	}

	int cnt = 0;
	while (1) {
		bfs();
		cnt++;

		if (dist[n][n]) break;
		memset(dist, 0, sizeof(dist));
	}
	cout << cnt - 1;
}