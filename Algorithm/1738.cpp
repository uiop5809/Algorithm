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

int n, m, u, v, w;
const int INF = 1e9;
bool cycle;
bool c[101];
int pre[101];

vector <int> rev[101]; // 정점 번호에서 역추적하여 닿을 수 있는 정점들 check
vector <int> dist;
vector <pair <int, int>> edge[101];

void bellman_ford() {
	dist.resize(n + 1, INF);
	dist[1] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j].first;
				int nextcost = edge[i][j].second;

				if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					pre[next] = i;
					if (k == n && c[next]) cycle = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 금품의 많을수록 좋으니 양의 무한대가 되면 안 됨
	// But 가중치 * -1 해줬으니 음의 무한대가 되면 안 됨
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ v, -w }); // 이웃노드, 가중치
		rev[v].push_back(u);
	}

	// 사이클이 있다고 무조건 -1 출력 X
	// 도착지점까지 이동 중, 음의 사이클이 존재하면 -1
	queue <int> q;
	q.push(n);
	c[n] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < rev[now].size(); i++) {
			int next = rev[now][i];
			if (!c[next]) {
				c[next] = 1;
				q.push(next);
			}
		}
	}

	bellman_ford();

	if (cycle) cout << -1;
	else {
		vector <int> res;
		int temp = n;
		while (temp) {
			res.push_back(temp);
			temp = pre[temp];
		}
		for (int i = res.size() - 1; i >= 0; i--) 
			cout << res[i] << " ";
	}
}