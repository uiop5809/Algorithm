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

int N, K, cnt = 0, res;
bool c[100001];

queue <pair <int, int>> q;

void bfs(int start, int end) {
	q.push({ start, 0 });
	c[start] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		c[x] = 1;

		// 똑같은 시간대에 동생 위치에 또 도착
		if (cnt && x == end && res == time) {
			cnt++;
		}
		// 처음으로 동생 위치에 도착
		if (!cnt && x == end) {
			res = time;
			cnt++;
		}
		
		if (x - 1 >= 0 && !c[x - 1]) {
			q.push({ x - 1, time + 1 });
		}
		if (x + 1 < 100001 && !c[x + 1]) {
			q.push({ x + 1, time + 1 });
		}
		if (x * 2 < 100001 && !c[x * 2]) {
			q.push({ x * 2, time + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	bfs(N, K);
	cout << res << "\n" << cnt;
}