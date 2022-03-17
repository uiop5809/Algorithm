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

int N, M, sum;
int num[101][101];
int cnt[101][101];
bool c[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs() {
	q.push({ 1, 1 });
	c[1][1] = 1;

	sum = 0;
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
				sum++;
			}
			else if (num[nx][ny] == 1) {
				cnt[nx][ny]++;

				if (cnt[nx][ny] >= 2) {
					num[nx][ny] = 0;
					c[nx][ny] = 1;
				}
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
		bfs();
		res++;
		memset(c, 0, sizeof(c));
		memset(cnt, 0, sizeof(cnt));

		if (sum == N * M - 1) break;
	}
	cout << res - 1;
}