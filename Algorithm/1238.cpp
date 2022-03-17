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

int N, M, X, x, y, t;
const int INF = 1e9;

vector <pair <int, int>> edge[1001];

priority_queue <pair <int, int>> pq;

int dijkstra(int from) {
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
	return dist[X];
}

int dijkstra1(int to) {
	vector <int> dist(N + 1, INF);
	dist[X] = 0;
	pq.push({ 0, X });

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

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> t; 
		edge[x].push_back({ y, t }); // 이웃노드, 가중치
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		res = max(dijkstra(i) + dijkstra1(i), res);
	}
	cout << res;
}