#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

int N, M, A, B, T, W;

vector <int> dist;
vector <pair <int, pair <int, int>>> edge[20001];

priority_queue <pair <int, int>> pq;

int dijkstra() {
	dist.resize(N + 1, INF);
	dist[1] = 0;
	pq.push({ 0, 1 }); // 가중치, 정점

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int nextcost = edge[now][i].second.first;
			int term = edge[now][i].second.second;

			if (now == 1) {
				if (dist[next] > dist[now] + nextcost) {
					dist[next] = dist[now] + nextcost;
				}
			}
			else {
				if (term > dist[now]) {
					dist[next] = dist[now] + nextcost;
					dist[next] += term - dist[now];
				}
				else {
					if (dist[now] % term == 0) {
						dist[next] = dist[now] + nextcost;
					}
					/*else {
						dist[next] = dist[now] + nextcost;
						dist[next] += dist[now] % term;
					}*/
				}
			}
			pq.push({ -dist[next], next });
		}
	}
	return dist[N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> T >> W;
		edge[A].push_back({ B, {T, W}});
	}
	cout << dijkstra();
}