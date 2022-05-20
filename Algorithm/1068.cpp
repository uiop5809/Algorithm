#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int c[51];
int N, n, root, deleteNode;

queue<int> q;
vector<int> tree[51];

void bfs() {
	memset(c, 0, sizeof(c));
	if (root == deleteNode) return;
	q.push(root);
	c[root] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			if (next == deleteNode || c[next] != 0) continue;
			q.push(next);
			c[now]++;
			c[next] = 1;
		}
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n == -1) root = i;
		else tree[n].push_back(i);
	}
	cin >> deleteNode;
	bfs();

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (c[i] == 1) res++;
	}
	cout << res;
}