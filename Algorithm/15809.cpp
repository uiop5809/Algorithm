#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, M, op, P, Q;
int parent[100001], res[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int op, int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b){
		if (res[a] < res[b]) swap(a, b); 
		parent[b] = a;
		if (op == 1) res[a] += res[b];
		else res[a] -= res[b];
		res[b] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		cin >> res[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> op >> P >> Q;
		unionParent(op, P, Q);
	}

	vector <int> v;
	for (int i = 1; i <= N; i++) {
		if (res[i] > 0) v.push_back(res[i]);
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}