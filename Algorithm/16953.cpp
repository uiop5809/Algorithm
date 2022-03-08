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

int A, B;
bool flag = 0;

queue <pair <long long, long long>> q;

void bfs(int a, int b) {
	q.push({a, 1});

	while (!q.empty()) {
		long long num = q.front().first;
		long long cnt = q.front().second;
		q.pop();

		if (num == b) {
			cout << cnt;
			flag = 1;
			break;
		}
		if (num * 2 <= b) {
			q.push({ num * 2, cnt + 1 });
		}
		if (num * 10 + 1 <= b) {
			q.push({ num * 10 + 1, cnt + 1 });
		}
	}
	if (!flag) cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	bfs(A, B);
}