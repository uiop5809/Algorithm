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
#define INF 10000000001

int N, M, x, y, z;
int num[100001];

vector <long long> dist;
vector <pair <int, int>> edge[100001];

priority_queue <pair <long long, int>> pq;

void dijkstra() {
	dist.resize(N, INF);
	dist[0] = 0;
	pq.push({ 0, 0 }); // 가중치, 정점

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (num[now] || dist[now] < cost) continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			long long nextcost = edge[now][i].second;

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
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z });
		edge[y].push_back({ x, z });
	}
	dijkstra();

	if (dist[N - 1] != INF) cout << dist[N - 1];
	else cout << -1;
}