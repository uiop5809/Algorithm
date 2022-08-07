#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int arr[1000][1000];

int N, M, dir, resy, resx;
int y, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = N * N; i > 0; i--) {
		arr[y][x] = i;
		if (i == M) {
			resy = y + 1;
			resx = x + 1;
		}
		if (y + dy[dir] < 0 || y + dy[dir] >= N || x + dx[dir] < 0 || x + dx[dir] >= N || arr[y + dy[dir]][x + dx[dir]] != 0) {
			dir = (dir + 1) % 4;
		}
		y += dy[dir];
		x += dx[dir];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << resy << " " << resx << "\n";
}