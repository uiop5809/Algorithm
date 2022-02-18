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
	int N, M, num, cnt = 0;
	int index = 0;

	cin >> N >> M;
	deque <int> d;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;

		for (int j = 0; j < d.size(); j++) {
			if (d[j] == num) {
				index = j;
				break;
			}
		}
		while (num != d.front()) {
			if (index <= d.size() / 2) {
				d.push_back(d.front());
				d.pop_front();
			}
			else {
				d.push_front(d.back());
				d.pop_back();
			}
			cnt++;
		}
		if (num == d.front()) {
			d.pop_front();
		}
	}
	cout << cnt;
}