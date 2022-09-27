#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>
#include <cmath>
#include <climits>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int V, E, x, y, z, from;
int num[11];

vector <pair <int, int>> edge[10001];

priority_queue <pair <long long, int>> pq;

long long dijkstra(int start, int end) {
	vector <long long> dist(V + 1, LLONG_MAX);
	dist[start] = 0;
	pq.push({ 0, start});

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) 
			continue; 
		for(int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			long long nextcost = edge[now][i].second; 

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

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z }); // 이웃노드, 가중치
		edge[y].push_back({ x, z });
	}
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}
	cin >> from;

	vector <int> v;
	
	int ynow = num[0];
	long long ydist = 0;
	for (int i = 0; i < 10; i++) {
		long long ndist = dijkstra(ynow, num[i]);
		if (ndist == LLONG_MAX) continue;
		ydist += ndist;
		ynow = num[i];

		long long mdist = dijkstra(from, num[i]);
		if (mdist < 0) continue;
		if (ydist >= mdist) v.push_back(num[i]);
	}

	if (v.empty()) cout << -1;
	else {
		sort(v.begin(), v.end());
		cout << v.front();
	}
}