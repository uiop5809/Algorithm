#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N, M, tp;
int parent[51], tpeople[51], people[51][51];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
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

	cin >> N >> M >> tp;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < tp; i++) {
		cin >> tpeople[i];
	}
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> people[i][j];
		}
		for (int j = 0; j < n - 1; j++) {
			unionParent(people[i][j], people[i][j + 1]);
		}	
	}

	int res = 0;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = 0; j < tp; j++) {
			for (int k = 0; k < M; k++) {
				if (getParent(tpeople[j]) == getParent(people[i][k])) {
					cnt++;
					break;
				}
			}
		}
		if (cnt == 0) res++;
	}
	cout << res;
}