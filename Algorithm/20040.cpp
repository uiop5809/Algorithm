#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int n, m, x, y;
int parent[500001];

// 부모 노드를 찾는 함수
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 두 부모 노드를 작은 것으로 합치는 함수
bool unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else {
		if (a > b) parent[a] = b;
		else parent[b] = a;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (unionParent(x, y)) {
			res = i + 1;
			break;
		}
	}
	cout << res;
}