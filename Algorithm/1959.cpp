#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
long long arr[101][101];
long long x, y, dir, resy, resx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long M, N, cnt = 0;
	cin >> M >> N;
	for (int i = 0; i < M * N; i++) {
		arr[y][x] = 1;

		if (i == M * N - 1) {
			resy = y + 1;
			resx = x + 1;
		}
		if (x + dx[dir] < 0 || x + dx[dir] >= N || y + dy[dir] < 0 || y + dy[dir] >= M || arr[y + dy[dir]][x + dx[dir]] != 0) {
			dir = (dir + 1) % 4;
			cnt++;
		}
		y += dy[dir];
		x += dx[dir];
	}
	cout << cnt - 1 << "\n";
	cout << resy << " " << resx;
}
