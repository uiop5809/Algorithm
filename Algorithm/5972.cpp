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

int N, M, x, y, z;
const int INF = 1e9;

vector <int> dist;
vector <pair <int, int>> edge[50001];

priority_queue <pair <int, int>> pq;

void dijkstra() {
	dist.resize(N + 1, INF); // 모든 정점 무한대로
	dist[1] = 0; // 시작 정점 0으로
	pq.push({ 0, 1 }); // 가중치, 시작정점

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
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z }); // 이웃 노드, 가중치
		edge[y].push_back({ x, z });
	}
	dijkstra();
	cout << dist[N];
}