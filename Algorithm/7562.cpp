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

int T, l, fromX, toX, fromY, toY;
int num[301][301];
int dist[301][301];

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

queue <pair <int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == toX && y == toY){
			cout << dist[x][y] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}	

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l)
				continue;
			if (!dist[nx][ny]) {
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> l;
		cin >> fromX >> fromY >> toX >> toY;
		bfs(fromX, fromY);

		memset(num, 0, sizeof(num));
		memset(dist, 0, sizeof(dist));
	}
}