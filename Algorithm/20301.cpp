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

int N, K, M, cnt = 0;
bool check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K >> M;

	deque <int> d;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}

	while (!d.empty()) {
		if (check == 0) {
			for (int i = 0; i < K - 1; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		
		else {
			for (int i = 0; i < K - 1; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		cnt++;
		if (cnt == M) {
			check = !check;
			cnt = 0;
		}
	}

}