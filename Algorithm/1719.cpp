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

int n, m, x, y, z;
int arr[201][201];
int res[201][201];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= n; k++) { // 경유지
		for (int i = 1; i <= n; i++) { // 출발지
			for (int j = 1; j <= n; j++) { // 도착지
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					if (i != k) res[i][j] = res[i][k];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		arr[x][y] = arr[y][x] = z;
		res[x][y] = y;
		res[y][x] = x;
	}
	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "-" << " ";
			else cout << res[i][j]<< " ";
		}
		cout << "\n";
	}
}