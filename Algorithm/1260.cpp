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

int c[1001];
vector <int> v[1001];

void edge(int i, int j) {
	v[i].push_back(j);
	v[j].push_back(i);
}

void bfs(int n) {
	queue <int> q;
	q.push(n);
	c[n] = true;

	while (!q.empty()) {
		int num1 = q.front();
		cout << num1 << " ";
		q.pop();
		for (int i = 0; i < v[num1].size(); i++) {
			int num2 = v[num1][i];
			if (!c[num2]) {
				q.push(num2);
				c[num2] = true;
			}
		}
	}
}

void dfs(int n) {
	if (c[n]) return;

	cout << n << " ";
	c[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int num1 = v[n][i];
		if (!c[num1]) {
			dfs(num1);
		}
	}

}

int main() {
	int N, M, V, x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edge(x, y);
	}

	//정점 작은 것부터 방문
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V);
	cout << "\n";
	memset(c, 0, sizeof(c)); // 방문체크 배열 초기화
	bfs(V);
}