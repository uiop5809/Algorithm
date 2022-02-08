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
	int n;
	int num[501][501];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			num[i - 1][j] += max(num[i][j], num[i][j + 1]);
		}
	}

	cout << num[0][0];
}