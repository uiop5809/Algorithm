#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;
#define INF 2100000000

int N, M, x, y, z;
long long dist[501];
bool cycle;

vector <pair <int, int>> edge[501];

void bellman_ford() {
	// �����Ϸ��� ������ ���� �����ּ�, �����Ϸ��� ���� ����, ���� ��
	fill(dist, dist + N + 1, INF); 
	dist[1] = 0;

	for (int k = 1; k <= N; k++) { // V�� �ݺ� 0 ~ V-1��°������ �ִ� �Ÿ� ������ ����
		for (int i = 1; i <= N; i++) { // ��� ������ ����
			for (int j = 0; j < edge[i].size(); j++) { // �� ������ ��� ������ ����
				int next = edge[i][j].first;
				int nextcost = edge[i][j].second;

				if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N) cycle = true; // V��° Ž���� ���� ����Ŭ �Ǻ��� ����
				}
			}
		}
	}
	if (cycle) cout << -1;
	else {
		for (int i = 2; i <= N; i++) 
			cout << (dist[i] != INF ? dist[i] : -1) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, z });
	}
	bellman_ford();
}