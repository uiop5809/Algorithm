#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
int parent[1000001];

// �θ� ��带 ã�� �Լ�
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// �� �θ� ��带 ���� ������ ��ġ�� �Լ�
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

// �θ� ��尡 ������ Ȯ��
void findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (!op) unionParent(a, b);
		else findParent(a, b);
	}
}