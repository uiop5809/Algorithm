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

int n, m, x, y, z;
long long dist[101];
long long res[101];
bool cycle;

vector <pair <int, int>> edge[101];

void bellman_ford() {
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j].first;
				int nextcost = edge[i][j].second;

				if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					res[next] = i;
					if (k == n) cycle = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ y, -z }); // 이웃노드, 가중치
	}
	bellman_ford();

	vector <int> ans;
	long long temp = n;
	while (temp) {
		ans.push_back(temp);
		temp = res[temp];
	}

	if (cycle) cout << -1;
	else {
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}