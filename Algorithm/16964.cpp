#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, x, y, num[100001], order[100001];
bool c[100001];

vector<int> v;
vector<int> tree[100001]; // °£¼±

bool cmp(int a, int b) {
	return order[a] < order[b];
}

void dfs(int n) {
	c[n] = true;
	v.push_back(n);

	for (int i = 0; i < tree[n].size(); i++) {
		if(!c[tree[n][i]]) dfs(tree[n][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		order[num[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		sort(tree[i].begin(), tree[i].end(), cmp);
	}

	dfs(1);
	for (int i = 1; i <= N; i++) {
		if (num[i] != v[i - 1]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}