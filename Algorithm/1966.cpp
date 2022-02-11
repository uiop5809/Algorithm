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

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n, m; //문서의 개수, 몇번째
		int cnt = 0;

		queue <pair <int, int>> q;
		priority_queue <int> pq;

		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			q.push({ j, num }); //인덱스와 중요도
			pq.push(num); //우선순위에는 중요도만
		}

		while (!q.empty()) {
			int cindex = q.front().first;
			int cval = q.front().second;

			q.pop();

			if (pq.top() == cval) {
				pq.pop();
				cnt++;

				if (m == cindex) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ cindex, cval });
			}
		}
	}
}