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

int N, M, x, y, cnt;
int c[1001];

vector <int> v[1001];

void edge(int x, int y) {
	v[x].push_back(y);
	v[y].push_back(x);
}

void dfs(int n) {
	queue <int> q;
	q.push(n);
	c[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!c[next]) {
				q.push(next);
				c[next] = 1;
			}
		}
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edge(x, y);
	}
	for (int i = 1; i <= N; i++){
		if (!c[i]) {
			dfs(i);
		}
	}
	cout << cnt;
}