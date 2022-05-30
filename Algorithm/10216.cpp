#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int T, N, x, y, R, parent[10001];

vector <pair <int, pair <int, int>>> v;

int getParent(int x) {
	if (x == parent[x]) return x;
	else parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> R;
			v.push_back({ R, {x, y} });
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i == j) continue;
				if (pow(v[i].first )) {

				}
			}
		}
	}
}