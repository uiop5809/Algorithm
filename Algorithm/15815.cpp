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

	string num;
	getline(cin, num);

	stack <int> s;
	for (int i = 0; i < num.length(); i++) {
		char c = num[i];
		
		if (c >= '0' && c <= '9') {
			s.push(c - '0');
		}
		else {
			int a, b;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();

			if (c == '+') {
				s.push(b + a);
			}
			else if (c == '-') {
				s.push(b - a);
			}
			else if (c == '*') {
				s.push(b * a);
			}
			else if (c == '/') {
				s.push(b / a);
			}
		}
	}

	cout << s.top();
}