#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R, x, y, idx = 1;
long long res[100001], c[100001];
vector<vector<int>> v(100001);

void dfs(int start, int cnt) {
	c[start] = idx++;
	res[start] = cnt;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!c[next]) dfs(next, cnt + 1);
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

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (c[i]) sum += c[i] * res[i];
		else sum += c[i] * -1;
	}
	cout << sum;
}