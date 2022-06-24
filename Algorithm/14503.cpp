#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, r, c, d;
int num[51][51];
bool check[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue <pair <int, pair <int, int>>> q;

void bfs(int x, int y, int d) {
	q.push({ d, {x, y}});
	check[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nd = (d + 3 - i) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];

			if (nx < 0 || nx > r || ny < 0 || ny > c) 
				continue;
			if (!check[nx][ny] && num[nx][ny] == 0) {
				bool flag = true;
				check[nx][ny] = 1;
				q.push({ nd, {nx, ny} });
			}
		}
		if (!flag) {
			int nd = (d + 2) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx < 0 || nx > r || ny < 0 || ny > c)
				continue;
			q.push({ nd, {nx, ny}});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
		}
	}
	bfs(r, c, d);

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j]) res++;
		}
	}
	cout << res;
}