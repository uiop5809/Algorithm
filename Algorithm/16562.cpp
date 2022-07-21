#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, k, v, w;
int f[10001], parent[10001];

// 부모 노드를 찾는 함수
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 부모 노드를 작은 노드로 합치는 함수
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (f[a] > f[b]) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		cin >> f[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		unionParent(v, w);
	}

	vector <int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(getParent(i));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += f[v[i]];
	}
	if (sum <= k) cout << sum;
	else cout << "Oh no";
}