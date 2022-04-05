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
#define INF 2500000000

int N, from, to, M, x, y, z;
int money[51];
bool c[51];

vector <long long> dist;
vector <pair <int, int>> edge[51];

// 사이클이 생기는 노드에서 to로 갈 수 있는지 체크
bool bfs(int from, int to) {
	if (from == to) return true;

	queue <int> q;
	q.push(from);
	c[from] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			if (c[next]) continue;
			c[next] = 1;
			if (next == to) return true;
			q.push(next);
		}
	}
	return false;
}

int bellman_ford(int from, int cycle) {
	dist.resize(N + 1, INF);
	dist[from] = -money[from];

	for (int k = 1; k <= N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j].first;
				long long nextcost = edge[i][j].second - money[next];

				if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N && bfs(next, to)) return next;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> from >> to >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z }); // 이웃노드, 가중치
	}
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	int res = bellman_ford(from, 1);

	if (dist[to] == INF) cout << "gg"; // 갈 수 없음
	else if (res != -1) cout << "Gee"; // 갈 수 있지만 cycle 존재
	else cout << -dist[to]; // 갈 수 있고 cycle 없음
}