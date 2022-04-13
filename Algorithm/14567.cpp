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

int N, M, A, B;
int indegree[1001]; // 진입차수
int res[1001];

queue <int> q;
vector <int> v[1001];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			res[next] = max(res[next], res[now] + 1);
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
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	topologySort();
	for (int i = 1; i <= N; i++) {
		cout << res[i] << " ";
	}
}