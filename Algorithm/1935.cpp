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
	int N;
	double alpha[26];
	string str;

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> alpha[i];
	}
	stack <double> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();

			switch (str[i]) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			}
		}
		else {
			s.push(alpha[str[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();

}