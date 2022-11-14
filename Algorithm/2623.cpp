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

int N, M, Mnum, x[1001];
int indegree[1001];

queue <int> q;
vector <int> v[1001];
vector <int> res;

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		res.push_back(now);

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> Mnum;
		for (int j = 1; j <= Mnum; j++) {
			cin >> x[j];
		}
		for (int j = 1; j < Mnum; j++) {
			for (int k = j + 1; k <= Mnum; k++) {
				v[x[j]].push_back(x[k]);
				indegree[x[k]]++;
			}
		}
		memset(x, 0, sizeof(x));
	}
	topologySort();

	if (res.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << res[i] << "\n";
		}
	}
	else cout << 0;
}