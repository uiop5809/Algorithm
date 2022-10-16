#include <algorithm>
#include <iostream>
using namespace std;

int T, N, x, y;
int parent[20001], dist[20001];

int getParent(int x) {
	if (parent[x] == x) return x;
	else {
		int temp = getParent(parent[x]);
		dist[x] += dist[parent[x]];
		parent[x] = temp;
		return temp;
		/* int idx = getParent(parent[x]);
		dist[x] += dist[parent[x]];
		return parent[x] = idx; */
	}
}

void unionParent(int a, int b) {
	dist[a] = abs(a - b) % 1000;
	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			dist[i] = 0;
		}
		while (1) {
			char c;
			cin >> c;
			if (c == 'O') break;
			else if (c == 'E') {
				cin >> x;
				getParent(x);
				cout << dist[x] << "\n";
			}
			else if (c == 'I') {
				cin >> x >> y;
				unionParent(x, y);
			}
		}
	}
}