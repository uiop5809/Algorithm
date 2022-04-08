#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, K;
bool c[100001];

priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq; // line, time

int bfs() {
	pq.push({ 0, N });
	c[N] = 1;

	while (!pq.empty()) {
		int time = pq.top().first;
		int line = pq.top().second;
		pq.pop();

		if (line == K) return time;

		if (line * 2 <= 100000 && !c[line * 2]) {
			pq.push({ time, line * 2 });
			c[line * 2] = 1;
		}
		if (line + 1 <= 100000 && !c[line + 1]) {
			pq.push({ time + 1, line + 1 });
			c[line + 1] = 1;
		}
		if (line - 1 >= 0 && !c[line - 1]) {
			pq.push({ time + 1, line - 1 });
			c[line - 1] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	cout << bfs();
}