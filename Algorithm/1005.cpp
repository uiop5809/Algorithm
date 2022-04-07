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

int T, N, K, x, y, W;
int build[1001];
int indegree[1001]; // 진입차수
int res[1001]; 

queue <int> q;
vector <int> v[1001];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = build[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			res[next] = max(res[next], res[now] + build[next]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) { // 각 건물당 건설 시간
			cin >> build[i];
		}
		for (int i = 0; i < K; i++) { // 건설 순서
			cin >> x >> y;
			v[x].push_back(y);
			indegree[y]++;
		}
		cin >> W;

		topologySort();
		cout << res[W] << "\n";

		memset(build, 0, sizeof(build));
		memset(indegree, 0, sizeof(indegree));
		memset(res, 0, sizeof(res));
		memset(v, 0, sizeof(v));
	}
}