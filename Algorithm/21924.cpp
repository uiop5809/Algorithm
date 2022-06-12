#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, a, b, c;
int parent[100001];

vector <pair <int, pair <int, int>>> v;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

bool connect() {
	for (int i = 2; i <= N; i++) {
		if (getParent(i) != getParent(1)) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	long long res = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
		res += c;
	}
	sort(v.begin(), v.end());
	
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		int cost = v[i].first;
		int start = v[i].second.first;
		int end = v[i].second.second;

		int a = getParent(start);
		int b = getParent(end);

		if (a == b) continue;
		if (a > b) parent[a] = b;
		else parent[b] = a;

		sum += cost;
	}
	if (connect()) cout << res - sum;
	else cout << -1;
}