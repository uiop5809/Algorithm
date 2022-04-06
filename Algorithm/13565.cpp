#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int M, N;
int num[1001][1001];
bool c[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > M || ny < 1 || ny > N)
				continue;
			if (num[nx][ny] != 1 && !c[nx][ny]) {
				c[nx][ny] = 1;
				num[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &num[i][j]);
			if (i == 1 && !num[i][j]) {
				q.push({ i, j });
				c[i][j] = 1;
			}
		}
	}
	bfs();

	bool ans = false;
	for (int i = 1; i <= N; i++) {
		if (num[M][i] == 2) ans = true;
	}
	if (ans) cout << "YES";
	else cout << "NO";
}