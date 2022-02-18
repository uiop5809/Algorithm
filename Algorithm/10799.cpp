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
	stack <char> s;
	string str;

	int cnt = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')' && str[i - 1] == '(') {
			s.pop();
			cnt += s.size();
		}
		else {
			cnt++;
			s.pop();
		}
	}
	cout << cnt;

}