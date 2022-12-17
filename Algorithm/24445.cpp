#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, x, y, c[100001], res[100001], idx = 1;
vector<vector<int>> v(100001);

void bfs(int start) {
	queue<int> q;
	c[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		res[now] = idx++;
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!c[next]) {
				c[next] = 1;
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
		sort(v[i].rbegin(), v[i].rend());
	}
	bfs(R);
	for (int i = 1; i <= N; i++) {
		cout << res[i] << "\n";
	}
}