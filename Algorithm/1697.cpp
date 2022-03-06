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

int N, K;
bool c[100001];

queue <pair<int, int>> q; // line, time

int bfs(int start, int end) {
	q.push({ start, 0 });
	c[start] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == end) {
			return t;
		}
		if (x + 1 < 100001 && !c[x + 1]) {
			q.push({ x + 1, t + 1 });
			c[x + 1] = 1;
		}
		if (x - 1 >= 0 && !c[x - 1]) {
			q.push({ x - 1, t + 1 });
			c[x - 1] = 1;
		}
		if (x * 2 < 100001 && !c[x * 2]) {
			q.push({ x * 2, t + 1 });
			c[x * 2] = 1;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << bfs(N, K);
}