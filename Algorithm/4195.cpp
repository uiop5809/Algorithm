#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int T, F;
int parent[200001], res[200001];
string a, b;

// �θ� ��带 ã�� �Լ�
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// �� �θ� ��带 ���� �θ�� ��ġ�� �Լ�
int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) { // �ٸ� ����
		parent[b] = a; // ���� ����
		res[a] += res[b];
		res[b] = 1;
	}
	return res[a];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> F;
		for (int i = 1; i <= 2 * F; i++) {
			parent[i] = i;
			res[i] = 1;
		}
		int idx = 1;
		map <string, int> name;
		for (int i = 0; i < F; i++) {
			cin >> a >> b;
			if (name.count(a) == 0) name[a] = idx++;
			if (name.count(b) == 0) name[b] = idx++;
			cout << unionParent(name[a], name[b]) << "\n";
		}
	}
}