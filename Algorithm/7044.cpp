#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A, B, C;
int parent[1001];

vector <pair <int, pair <int, int>>> v;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v.push_back({ C, {A, B} });
	}
	sort(v.rbegin(), v.rend());

	int sum = 0, cnt = 0;
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
		cnt++;
		if (cnt == N - 1) {
			cout << sum;
			return 0;
		}
	}
	cout << -1;
	return 0;
}