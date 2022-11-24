#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, m, x, y, parent[501];
bool cycle[501];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc = 1;
	while (1) {
		int cnt = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			cycle[i] = false;
		}
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			int start = getParent(x);
			int end = getParent(y);

			if (start != end) { // 다른 집합
				if (cycle[start] || cycle[end]) {
					cycle[start] = cycle[end] = true;
				}
				parent[end] = start;
			}
			else { // 같은 집합
				cycle[start] = true;
			}
		}

		map <int, int> m;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int x = getParent(i);
			if (cycle[x]) continue;
			if (m.count(x) == 0) {
				m[x] = 1;
				res++;
			}
		}
		cout << "Case " << tc; tc++;
		if (res == 0) cout << ": No trees.\n";
		else if (res == 1) cout << ": There is one tree.\n";
		else if (res > 1) cout << ": A forest of " << res << " trees.\n";
	}
	return 0;
}