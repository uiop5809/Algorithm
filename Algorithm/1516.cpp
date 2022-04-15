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

int N, times[501];
int indegree[501];
int res[501];

queue <int> q;
vector <int> v[501];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = times[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			res[next] = max(res[next], res[now] + times[next]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> times[i];
		int x = 0;
		while (x != -1) {
			cin >> x;
			if (x != -1) {
				v[x].push_back(i);
				indegree[i]++;
			}
		}
	}
	topologySort();

	for (int i = 1; i <= N; i++) {
		cout << res[i] << "\n";
	}
}