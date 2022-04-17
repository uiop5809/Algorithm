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

int n, k, x, y, s, xs, ys;
int num[401][401];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (num[i][k] == 1 && num[k][j] == 1) {
					num[i][j] = 1;
					num[j][i] = 2;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) num[i][j] = INF;
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		num[x][y] = 1;
		num[y][x] = 2;
	}
	floyd();

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> xs >> ys;
		if (num[xs][ys] == 1) cout << -1;
		else if (num[xs][ys] == 2) cout << 1;
		else cout << 0;
		cout << "\n";
	}
}