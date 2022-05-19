#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, u, v, d, parent[1001];
char gender[1001];

vector <pair <int, pair <int, int>>> graph;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> gender[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> d;
		if (gender[u] != gender[v]) {
			graph.push_back({ d, {u, v} });
		}
	}
	sort(graph.begin(), graph.end());

	int sum = 0, cnt = 0;
	for (int i = 0; i < graph.size(); i++) {
		int cost = graph[i].first;
		int start = graph[i].second.first;
		int end = graph[i].second.second;

		int a = getParent(start);
		int b = getParent(end);

		if (a == b) continue;
		if (a > b) parent[a] = b;
		else parent[b] = a;

		sum += cost;
		cnt++;
		if (cnt == N - 1) {
			cout << sum;
			break;
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (getParent(i) != getParent(1)) count++;
	}
	if (count > 0) cout << -1;
}