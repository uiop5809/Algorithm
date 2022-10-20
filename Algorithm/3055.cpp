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

int R, C, d1, d2;
bool c[51][51];
char graph[51][51];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };

queue <pair<int, int>> wq;
queue <pair<int, int>> gq;

int bfs() {
	int time = 0;
	while (!gq.empty()) {
		int wqsize = wq.size();
		int gqsize = gq.size();
		time++;

		while (wqsize--) {
			int x = wq.front().first;
			int y = wq.front().second;
			wq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > R || ny < 1 || ny > C) 
					continue;
				if (graph[nx][ny] == 'X' || graph[nx][ny] == 'D' || graph[nx][ny] == '*') 
					continue;
				wq.push({ nx, ny });
				graph[nx][ny] = '*';
			}
		}

		while (gqsize--) {
			int x = gq.front().first;
			int y = gq.front().second;
			gq.pop();

			c[x][y] = 1;
			if (x == d1 && y == d2) {
				cout << time - 1;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > R || ny < 1 || ny > C) 
					continue;
				if (graph[nx][ny] == 'X' || graph[nx][ny] == '*' || c[nx][ny]) 
					continue;
				c[nx][ny] = 1;
				gq.push({ nx, ny });
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') gq.push({ i, j });
			if (graph[i][j] == '*') wq.push({ i, j });
			if (graph[i][j] == 'D') { d1 = i; d2 = j; }
		}
	}
	bfs();
}