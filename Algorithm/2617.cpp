#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, x, y;
int num1[100][100], num2[100][100];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (num1[i][j] > num1[i][k] + num1[k][j]) {
					num1[i][j] = num1[i][k] + num1[k][j];
				}
				if (num2[i][j] > num2[i][k] + num2[k][j]) {
					num2[i][j] = num2[i][k] + num2[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			num1[i][j] = INF;
			num2[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		num1[x][y] = 1;
		num2[y][x] = 1;
	}
	floyd();

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= N; j++) {
			if (num1[i][j] != INF) {
				cnt1++;
			}
			if (num2[i][j] != INF) {
				cnt2++;
			}
		}
		if (cnt1 >= (N + 1) / 2 || cnt2 >= (N + 1) / 2) res++;
	}
	cout << res;
}