#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[5][5], res;
bool c[1000001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int sum, int cnt) {
	if (cnt == 5) {
		if (!c[sum]) {
			c[sum] = 1;
			res++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
		dfs(nx, ny, sum * 10 + arr[nx][ny], cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, arr[i][j], 0);
		}
	}
	cout << res;
}