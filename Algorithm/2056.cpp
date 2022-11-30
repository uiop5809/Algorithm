#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, x;
int t[10001];
int indegree[10001]; // 진입차수
int res[10001];

queue <int> q;
vector <int> v[10001];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = t[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			res[next] = max(res[next], res[now] + t[next]);
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			cin >> x;
			v[x].push_back(i);
		}
	}
	topologySort();

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, res[i]);
	}
	cout << ans;
}