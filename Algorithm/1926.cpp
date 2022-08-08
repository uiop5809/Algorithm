#include <iostream>
#include <queue>
using namespace std;

int n, m, arr[501][501];
bool c[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs(int x, int y) {
	queue <pair <int, int>> q;
	c[x][y] = 1;
	q.push({ x, y });
	int size = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		size++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (arr[nx][ny] == 1 && !c[nx][ny]) {
				q.push({ nx, ny });
				c[nx][ny] = 1;
			}
		}
	}
	return size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0, num, res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !c[i][j]) {
				num = bfs(i, j);
				res = max(res, num);
				cnt++;
			}
		}
	}
	cout << cnt << "\n" << res;
}