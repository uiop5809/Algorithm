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

const int INF = 1e9;

int V, E, K, x, y, w;

vector <int> dist;
vector <pair <int, int>> edge[20001];

priority_queue <pair <int, int>> pq;

void dijkstra() {
	dist.resize(V + 1, INF); // 모든 정점을 무한대로
	dist[K] = 0; // 시작 정점은 0으로
	pq.push({ 0, K }); // 가중치, 시작 정점

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue; // 현재 경로가 더 짧으면
		for (int i = 0; i < edge[now].size(); i++) { // 연결된 노드수만큼 반복
			int next = edge[now][i].first; // 연결된 노드
			int nextcost = edge[now][i].second; // 가중치

			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({ -dist[next], next }); // 음수로 저장
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> K; // 노드의 수, 간선의 수, 시작정점
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> w;
		edge[x].push_back({ y, w }); // 이웃노드 & 가중치
	}
	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}