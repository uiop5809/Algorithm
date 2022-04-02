#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, x, y, z;
int num[501][501];

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (num[i][j] > num[i][k] + num[k][j]) {
					num[i][j] = num[i][k] + num[k][j];
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
		}
	}
	floyd();
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		if (num[x][y] <= z) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}
}