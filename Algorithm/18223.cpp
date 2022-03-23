#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int V, E, P, x, y, z;
const int INF = 1e9;

vector <pair <int, int>> edge[5001];

priority_queue <pair <int, int>> pq;

int dijkstra(int start, int end) {
	vector <int> dist(V + 1, INF);
	dist[start] = 0;
	pq.push({ 0, start }); // 가중치, 시작 정점

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
	return dist[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z }); // 이웃노드, 가중치
		edge[y].push_back({ x, z });
	}

	if (dijkstra(1, P) + dijkstra(P, V) <= dijkstra(1, V))
		cout << "SAVE HIM";
	else cout << "GOOD BYE";
}