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

	string g;
	cin >> g;

	stack <char> s;

	for (int i = 0; i < g.length(); i++) {
		char c = g[i];

		if (g[i] == '(') {
			s.push('(');
		}
		else if (s.top() == ')') {
			s.pop();
		}
		else if (g[i] == '[') {
			s.push('[');
		}
		else if(s.top() == ']') {
			s.pop();
		}
	}

	if (s.empty()) {

	}
	else {
		cout << 0;
	}
}