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

string str;
stack <char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> str;

	int answer = 0, temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') { //올바르지 못함
				answer = 0;
				break;
			}
			if (str[i - 1] == '(') {
				answer += temp;
				temp /= 2;
				s.pop();
			}
			else {
				temp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				answer = 0;
				break;
			}
			if (str[i - 1] == '[') {
				answer += temp;
				temp /= 3;
				s.pop();
			}
			else {
				temp /= 3;
				s.pop();
			}
		}
	}
	if (!s.empty()) {
		answer = 0;
	}
	cout << answer;
}