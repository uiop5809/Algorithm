#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, a, b, c, parent[1001];
vector <pair <int, pair <int, int>>> v;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}
	sort(v.begin(), v.end());

	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int cost = v[i].first;
		int start = v[i].second.first;
		int end = v[i].second.second;

		int x = getParent(start);
		int y = getParent(end);

		if (x == y) continue;
		if (x < y) parent[y] = x;
		else parent[x] = y;

		sum += cost;
		cnt++;
		if (cnt == N - 1) {
			cout << sum;
			break;
		}
	}
}