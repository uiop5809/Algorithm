#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int n;
	string str[51];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < str[0].length(); i++) {
		char c = str[0][i];
		for (int j = 0; j < n; j++) {
			if (c != str[j][i]) {
				c = '?';
				break;
			}
		}
		cout << c;
	}
}