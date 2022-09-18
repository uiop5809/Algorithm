#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int n, m, A, B, cost, s, e;
bool c[10001];

vector <pair<int, int>> v[10001];

bool bfs(int cost) {
	queue <int> q;
	q.push(s);
	c[s] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == e) return true;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;

			if (!c[next] && nextcost >= cost) {
				c[next] = 1;
				q.push(next);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> cost;
		v[A].push_back({ B, cost });
		v[B].push_back({ A, cost });
		if (cost > max) max = cost;
	}
	cin >> s >> e;

	int left = 0, right = max;
	while (left <= right) {
		memset(c, 0, sizeof(c));

		int mid = (left + right) / 2;
		if (bfs(mid)) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
	return 0;
}