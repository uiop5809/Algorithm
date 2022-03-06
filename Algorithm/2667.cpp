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

int N, j = 0;
int num[26][26];
int c[101][101];
int res[676];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (num[nx][ny] == 1 && c[nx][ny] == 0) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
				cnt++;
			}
		}
	}
	res[j] = cnt + 1;
	j++;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &num[i][j]);
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (num[i][j] == 1 && c[i][j] == 0) {
				bfs(i, j);
				sum++;
			}
		}
	}
	cout << sum << "\n";

	sort(res, res + sum);
	for (int i = 0; i < sum; i++) {
		cout << res[i] << "\n";
	}
}