#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, a, b;
int dist[20001];

vector <int> edge[20001];

void bfs() {
	queue <int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < edge[x].size(); i++) {
			int nx = edge[x][i];

			if (!dist[nx]) {
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	bfs();

	vector <int> res;

	int max = 0;
	for (int i = 2; i <= N; i++) {
		if (max < dist[i]) max = dist[i];
	}
	for (int i = 2; i <= N; i++) 
		if (dist[i] == max) res.push_back(i);
	
	sort(res.begin(), res.end());
	cout << res[0] << " " << max - 1 << " " << res.size();
}