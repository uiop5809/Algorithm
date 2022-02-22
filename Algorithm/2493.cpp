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
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, height;
	stack <pair <int, int>> s;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> height;
		while (!s.empty()) {
			if (s.top().second > height) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0 ";
		}

		s.push({ i, height });
	}
}