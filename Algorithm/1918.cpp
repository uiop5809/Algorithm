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

	string str, res = "";
	cin >> str;

	stack <char> s;
	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			res += str[i];
		}
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					res += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case '+':
			case '-':
				while (!s.empty() && s.top() != '(') {
					res += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case ')':
				while (!s.empty() && s.top() != '(') {
					res += s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
	}	
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}

	cout << res;
}