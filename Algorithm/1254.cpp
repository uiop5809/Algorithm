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

int T, V, E, x, y;

vector <int> v[200001];
int color[200001]; // 1 »¡°­, 2 ÆÄ¶û

queue <int> q;

void bfs(int x) {
	q.push(x);
	color[x] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (!color[nx]) {
				q.push(nx);

				if (color[x] == 1) color[nx] = 2;
				else if (color[x] == 2) color[nx] = 1;
			}
		}
	}
}

bool result() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int nx = v[i][j];
			if (color[i] == color[nx]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= V; i++) {
			if (!color[i]) {
				bfs(i);
			}
		}
		if (result()) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		memset(color, 0, sizeof(color));
		memset(v, 0, sizeof(v));
	}
}