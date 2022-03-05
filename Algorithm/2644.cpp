#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int n, n1, n2, m, cnt;
int dist[101];

vector <int> v[101];

void edge(int x, int y) {
	v[x].push_back(y);
	v[y].push_back(x);
}

int bfs(int start, int end) {
	queue <int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == end) {
			return dist[end];
		}
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (!dist[next]) {
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> n1 >> n2 >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		edge(x, y);
	}
	cout << bfs(n1, n2);
}