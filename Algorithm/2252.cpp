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

int N, M, a, b;
int indegree[100001]; // 진입차수

queue <int> q;
vector <int> v[35000];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	topologySort();
}