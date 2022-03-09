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

int N, x, y;
int c[100001];
int parent[100001];

vector <int> v[100001];

void dfs(int now) {
	c[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (c[next] == 0) {
			parent[next] = now;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}	
}