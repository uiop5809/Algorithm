#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int d[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> d[i][j];
		}
	}
	
	while (r--) {
		int x1 = 0;
		int y1 = 0;

		int x2 = n - 1;
		int y2 = 0;

		int x3 = n - 1;
		int y3 = m - 1;

		int x4 = 0;
		int y4 = m - 1;

		while ((x1 < x2) && (y1 < y4)) {
			int temp = d[x2][y2];
			for (int i = x2; i > x1; i--) { //위 -> 아래
				d[i][y2] = d[i - 1][y2];
			}
			for (int i = y1; i < y4; i++) { //오른쪽 -> 왼쪽
				d[x1][i] = d[x1][i + 1];
			}
			for (int i = x4; i < x3; i++) { //아래 -> 위
				d[i][y4] = d[i + 1][y4];
			}
			for (int i = y3; i > y2; i--) { //왼쪽 -> 오른쪽
				d[x3][i] = d[x3][i - 1];
			}
			d[x2][y2 + 1] = temp;

			x1 += 1;
			y1 += 1;

			x2 -= 1;
			y2 += 1;

			x3 -= 1;
			y3 -= 1;

			x4 += 1;
			y4 -= 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}