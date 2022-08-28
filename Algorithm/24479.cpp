#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R, x, y, res[100001];
vector<vector<int>> v(100001);
int c[100001], idx = 1;

void dfs(int start) {
	c[start] = idx++;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!c[next]) dfs(next);
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
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << c[i] << "\n";
	}
}