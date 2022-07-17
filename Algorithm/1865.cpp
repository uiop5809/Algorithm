#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int TC, N, M, W, s, e, t;
const int INF = 1e9;
bool cycle;

void bellman_ford(vector <pair <int, int>> edge[]) {
	vector <int> dist(N + 1, INF);
	dist[1] = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j].first;
				int nextcost = edge[i][j].second;

				// 시작점을 하나로 잡으면 안 되고, 모든 정점에 대해 최단 거리 갱신해야돼서
				// dist[i] != INF 없애줌
				if (dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N) cycle = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> TC;
	while (TC--) {
		vector <pair <int, int>> edge[501];
		cycle = false;

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			edge[s].push_back({ e, t }); // 이웃노드, 시간
			edge[e].push_back({ s, t });
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			edge[s].push_back({ e, -t }); // 도착지점, 줄어드는 시간
		}

		bellman_ford(edge);
		cout << (cycle ? "YES" : "NO") << "\n";
	}
}