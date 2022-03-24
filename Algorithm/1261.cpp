#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int M, N;
string str;
int num[101][101];
int dist[101][101];

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

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (num[nx][ny] == 0 && !dist[nx][ny]) {
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
			if (num[nx][ny] == 1 && !dist[nx][ny]) {
				num[nx][ny] = 0;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			num[i][j] = str[j - 1] - '0';
		}
	}

	int cnt = 0;
	while(1) {
		bfs();
		cnt++;

		if (dist[N][M]) break;
		memset(dist, 0, sizeof(dist));
	}
	cout << cnt - 1;
}