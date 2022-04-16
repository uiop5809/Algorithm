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

int N, M;
int res = 1e9;
int num[51][51];
int dist[51][51];

vector <pair <int, int>> home;
vector <pair <int, int>> chicken;
vector <pair <int, int>> v;

void brute() {
	memset(dist, 0, sizeof(dist));

	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (!dist[home[i].first][home[i].second]) {
				dist[home[i].first][home[i].second] = abs(v[j].first - home[i].first) + abs(v[j].second - home[i].second);
			}
			else {
				dist[home[i].first][home[i].second] = min(dist[home[i].first][home[i].second], abs(v[j].first - home[i].first) + abs(v[j].second - home[i].second));
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum += dist[i][j];
		}
	}
	res = min(res, sum);
}

void dfs(int x, int cnt) {
	if (cnt == M) return brute();
	for (int i = x; i < chicken.size(); i++) {
		v.push_back({ chicken[i].first, chicken[i].second });
		dfs(i + 1, cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
			if (num[i][j] == 1) home.push_back({ i, j });
			else if (num[i][j] == 2) chicken.push_back({ i, j });
		}
	}
	dfs(0, 0);
	cout << res;
}