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

int N, E, a, b, c, v1, v2;
const int INF = 1e9;

vector <pair <int, int>> edge[801];

priority_queue <pair <int, int>> pq;

int dijkstra(int from, int to) {
	vector <int> dist(N + 1, INF);
	dist[from] = 0;
	pq.push({ 0, from });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int nextcost = edge[now][i].second;

			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist[to];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	int res1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
	int res2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

	if (dijkstra(1, v1) == INF || dijkstra(v1, v2) == INF || dijkstra(v2, N) == INF) cout << -1;
	else cout << min(res1, res2);
}