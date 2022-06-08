#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int T, H, W;
char arr[101][101];
bool c[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	c[x][y] = 1;
	q.push({x, y});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) continue;
			if (arr[nx][ny] == '#' && !c[nx][ny]) {
				c[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (arr[i][j] == '#' && !c[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		memset(arr, 0, sizeof(arr));
		memset(c, 0, sizeof(c));
	}
}