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

int N = 1;
int num[126][126];
int dist[126][126];
const int INF = 1e9;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

priority_queue <pair <int, pair <int, int>>> pq;

void dijkstra() {
	fill(&dist[1][1], &dist[N + 1][N + 1], INF);
	pq.push({ -num[1][1], {1, 1}}); // 가중치, 정점
	dist[1][1] = num[1][1];

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[x][y] < cost) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nextcost = num[nx][ny];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (dist[nx][ny] > dist[x][y] + nextcost) {
				dist[nx][ny] = dist[x][y] + nextcost;
				pq.push({ -dist[nx][ny], {nx, ny}});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; N != 0; i++) {
		cin >> N;
		if (N == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> num[i][j];
			}
		}
		dijkstra();
		cout << "Problem " << i << ": " << dist[N][N] << "\n";
	}
}