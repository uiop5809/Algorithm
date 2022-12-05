#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R, x, y, depth[100001];
vector<vector<int>> v(100001);
bool c[100001];

void dfs(int start, int cnt) {
	c[start] = 1;
	depth[start] = cnt;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if(!c[next]) dfs(next, cnt + 1);
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
	dfs(R, 0);
	for (int i = 1; i <= N; i++) {
		if (!c[i]) cout << -1 << "\n";
		else cout << depth[i] << "\n";
	}
}