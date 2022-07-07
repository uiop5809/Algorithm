#include <iostream>
#include <vector>
using namespace std;

int N, x, y, sum;
int c[500001];
vector<int> tree[500001];

void dfs(int s, int cnt) {
	// 리프노드, 루트노드 간선 무조건 1개
	if (tree[s].size() == 1 && s != 1) {
		sum += cnt;
		return;
	}
	for (int i = 0; i < tree[s].size(); i++) {
		if (!c[tree[s][i]]) {
			c[tree[s][i]] = true;
			dfs(tree[s][i], cnt + 1);
			c[tree[s][i]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1;i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	c[1] = true;
	dfs(1, 0);
	if (sum % 2 == 1) cout << "Yes" << "\n";
	else cout << "No" << "\n";
}