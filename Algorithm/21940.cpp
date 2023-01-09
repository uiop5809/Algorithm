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

int N, M, a, b, t, K, city[201];
int num[201][201];
const int INF = 1e9;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) num[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		num[a][b] = t;
	}
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> city[i];
	}
	floyd();

	int min = INF;
	vector <int> v;
	for (int i = 1; i <= N; i++) {
		int ans = 0;
		for (int j = 1; j <= K; j++) {
			if (num[i][city[j]] != INF && num[city[j]][i] != INF) {
				ans = max(num[i][city[j]] + num[city[j]][i], ans);
			}
		}
		if (min > ans) {
			v.clear();
			v.push_back(i);
			min = ans;
		}
		else if (min == ans) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}