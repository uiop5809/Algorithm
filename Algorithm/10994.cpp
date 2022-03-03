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

char arr[397][397];

void draw(int len, int r, int c) {
	for (int i = 0; i < len; i++) {
		if (i == 0 || i == len - 1) {
			for (int j = 0; j < len; j++) {
				arr[r + i][c + j] = '*';
			}
		}
		else {
			arr[r + i][c] = '*';
			arr[r + i][c + len - 1] = '*';
		}
	}
}

void square(int n, int r, int c) {
	int len = 4 * n - 3;
	draw(len, r, c);

	if (n == 1) {
		return;
	}
	square(n - 1, r + 2, c + 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			arr[i][j] = ' ';
		}
	}
	
	square(n, 0, 0);

	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}