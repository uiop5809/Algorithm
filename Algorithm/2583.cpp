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

int M, N, K;
int fromX, fromY, toX, toY;
int num[101][101];
bool c[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue <pair <int, int>> q;
vector <int> v;

void bfs(int x, int y) {
	q.push({ x, y });
	c[x][y] = 1;

	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (num[nx][ny] == 0 && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> fromX >> fromY >> toX >> toY;
		
		for (int j = fromY; j <= toY - 1; j++) {
			for (int k = fromX; k <= toX - 1; k++) {
				num[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (num[i][j] == 0 && !c[i][j]) {
				bfs(i, j);
			}
		}
	}

	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}