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
int indegree[32001];

priority_queue <int, vector <int>, greater <int>> pq;
vector <int> v[32001];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;

			if (indegree[next] == 0) {
				pq.push(next);
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
}