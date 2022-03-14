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
	dist.resize(V + 1, INF); // ��� ������ ���Ѵ��
	dist[K] = 0; // ���� ������ 0����
	pq.push({ 0, K }); // ����ġ, ���� ����

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue; // ���� ��ΰ� �� ª����
		for (int i = 0; i < edge[now].size(); i++) { // ����� ������ŭ �ݺ�
			int next = edge[now][i].first; // ����� ���
			int nextcost = edge[now][i].second; // ����ġ

			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({ -dist[next], next }); // ������ ����
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> K; // ����� ��, ������ ��, ��������
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> w;
		edge[x].push_back({ y, w }); // �̿���� & ����ġ
	}
	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}