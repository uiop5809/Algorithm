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

int T, N;
char alpha[1001];

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		deque <char> d;
		for (int i = 0; i < N; i++) {
			cin >> alpha[i];

			if (i == 0) {
				d.push_back(alpha[0]);
			}
			else if (alpha[i] <= d.front()) {
				d.push_front(alpha[i]);
			}
			else {
				d.push_back(alpha[i]);
			}
		}

		for (int i = 0; i < N; i++) {
			cout << d.front();
			d.pop_front();
		}
		cout << "\n";
	}
}