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
	int N, num;
	deque <pair<int,int>> d;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		d.push_back(make_pair(num, i));
	}

	while (!d.empty()) {
		int cnt = d.front().first;
		cout << d.front().second << " ";
		d.pop_front();

		if (!d.empty()) {
			if (cnt > 0) {
				for (int i = 0; i < cnt - 1; i++) {
					d.push_back(d.front());
					d.pop_front();
				}
			}
			else {
				for (int i = cnt; i < 0; i++) {
					d.push_front(d.back());
					d.pop_back();
				}
			}
		}
	}
}