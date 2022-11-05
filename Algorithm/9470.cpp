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

int T, K, M, P, A, B;
int indegree[1001];
int res[1001];

queue <int> q;
vector <int> v[1001];

void topologySort() {
	for (int i = 1; i <= M; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = 1;
		}
	}

	vector <int> num[1001];

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			num[next].push_back(res[now]);

			int mnum = 0;
			if (indegree[next] == 0) {
				q.push(next);

				for (int i = 0; i < num[next].size(); i++) {
					mnum = max(mnum, num[next][i]);
				}
				int cnt = 0;
				for (int i = 0; i < num[next].size(); i++) {
					if (mnum == num[next][i]) cnt++;
				}
				if (cnt == 1) res[next] = res[now];
				else if (cnt > 1) res[next] = mnum + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> K >> M >> P;
		for (int i = 0; i < P; i++) {
			cin >> A >> B;
			v[A].push_back(B);
			indegree[B]++;
		}
		topologySort();

		cout << K << " ";
		int ans = 0;
		for (int i = 1; i <= M; i++) {
			ans = max(ans, res[i]);
		}
		cout << ans << "\n";

		memset(indegree, 0, sizeof(indegree));
		memset(v, 0, sizeof(v));
		memset(res, 0, sizeof(res));
	}
}