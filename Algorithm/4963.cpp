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

int w, h;
int num[51][51];
bool c[51][51];

int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

queue <pair <int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > h || ny < 1 || ny > w)
				continue;
			if (num[nx][ny] == 1 && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while(1){
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> num[i][j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (num[i][j] == 1 && !c[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

		memset(c, 0, sizeof(c));
		memset(num, 0, sizeof(num));
	};
}