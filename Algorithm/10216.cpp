#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, x, y, z, parent[200001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		int sum = 0;
		vector <pair <int, pair <int, int>>> v;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			v.push_back({ z, {x, y} });
			sum += z;
		}
		sort(v.begin(), v.end());
		
		int cnt = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int cost = v[i].first;
			int start = v[i].second.first;
			int end = v[i].second.second;

			int x = getParent(start);
			int y = getParent(end);

			if (x == y) continue;
			if (x > y) parent[x] = y;
			else parent[y] = x;

			res += cost;
			cnt++;
			if (cnt == m - 1) {
				cout << sum - res << "\n";
				break;
			}
		}
	}
}