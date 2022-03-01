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

	string str;
	int M;

	cin >> str;
	stack <char> left;
	stack <char> right;

	for (int i = 0; i < str.length(); i++) {
		left.push(str[i]);
	}

	cin >> M;
	while (M--) {
		char cmd, c;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (cmd == 'P') {
			cin >> c;
			left.push(c);
		}
	}

	while(!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while(!right.empty()) {
		cout << right.top();
		right.pop();
	}
}