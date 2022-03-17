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

int T, n, d, c; // 컴퓨터, 의존성, 해킹당한 컴퓨터
int a, b, s; // a가 b 의존, b가 감염되면 s초 후 a도 감염
const int INF = 1e9;

priority_queue <pair <int, int>> pq;

void dijkstra(vector <pair <int, int>> edge[]) {
	vector <int> dist(n + 1, INF); // 모든 정점 무한대
	dist[c] = 0; // 시작 정점 0
	pq.push({ 0, c }); // 가중치, 시작 정점

	while (!pq.empty()) {
		int time = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < time) continue; // 현재보다 시간 더 클 떄

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first; 
			int nextTime = edge[now][i].second;

			if (dist[next] > dist[now] + nextTime) {
				dist[next] = dist[now] + nextTime;
				pq.push({ -dist[next], next });
			}
		}
	}
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			res = max(res, dist[i]);
		}
	}
	cout << cnt << " " << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> d >> c;
		vector <pair <int, int>> edge[10001];
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			edge[b].push_back({ a, s }); // a가 b 의존, b가 감염되면 s초 후 a도 감염
		}
		dijkstra(edge);
	}
}