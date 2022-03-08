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
int dist[51][51];
char guide[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

int bfs(int x, int y) {
	q.push({ x, y });
	dist[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (guide[nx][ny] == 'L' && !dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	int time = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (time < dist[i][j]) {
				time = dist[i][j];
			}
		}
	}
	memset(dist, 0, sizeof(dist));
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int Lcnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> guide[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (guide[i][j] == 'L') {
				if (max < bfs(i, j)) {
					max = bfs(i, j);
				}
			}
		}
	}
	cout << max - 1;
	return 0;
}