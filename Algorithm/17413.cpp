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
	string str;
	getline(cin, str);
	str += ' ';
	stack <char> s;
	bool check = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << '<';
			check = true;
		}
		else if (str[i] == '>') {
			cout << '>';
			check = false;
		}
		else if (check) {
			cout << str[i];
		}
		else if (str[i] == ' ') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
		else {
			s.push(str[i]);
		}
	}
	
}