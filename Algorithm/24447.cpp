#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, x, y, dist[100001], idx = 1;
long long res[100001], cnt[100001];
vector<vector<int>> v(100001);

void bfs(int start) {
	queue<int> q;
	dist[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt[now] = idx++;
		res[now] = dist[now] - 1;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!dist[next]) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	bfs(R);

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!dist[i]) sum += cnt[i] * -1;
		else sum += cnt[i] * res[i];
	}
	cout << sum;
}
