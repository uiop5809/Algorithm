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

int T, n, d, c; // ��ǻ��, ������, ��ŷ���� ��ǻ��
int a, b, s; // a�� b ����, b�� �����Ǹ� s�� �� a�� ����
const int INF = 1e9;

priority_queue <pair <int, int>> pq;

void dijkstra(vector <pair <int, int>> edge[]) {
	vector <int> dist(n + 1, INF); // ��� ���� ���Ѵ�
	dist[c] = 0; // ���� ���� 0
	pq.push({ 0, c }); // ����ġ, ���� ����

	while (!pq.empty()) {
		int time = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < time) continue; // ���纸�� �ð� �� Ŭ ��

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
			edge[b].push_back({ a, s }); // a�� b ����, b�� �����Ǹ� s�� �� a�� ����
		}
		dijkstra(edge);
	}
}