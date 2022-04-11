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

int n, m, r, x, y, z;
int num[101];
int arr[101][101];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= n; k++) { // 경유지
		for (int i = 1; i <= n; i++) { // 출발지점
			for (int j = 1; j <= n; j++) { // 도착지점
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) cin >> num[i];
	for (int i = 0; i < r; i++) {
		cin >> x >> y >> z;
		arr[x][y] = z;
		arr[y][x] = z;
	}
	floyd();

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] > m) continue;
			sum += num[j];
		}
		res = max(res, sum);
	}
	cout << res;
}