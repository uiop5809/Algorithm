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
	int n, m;
	cin >> n >> m;

	string str[51];

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == '.') {
				continue;
			}
			else {
				str[i][m - j - 1] = str[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << str[i] << "\n";
	}
	
}