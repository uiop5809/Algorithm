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

int N;
string n[65];

void recur(int x, int y, int size) {
	char color = n[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (n[i][j] != color) {
				cout << '(';
				recur(x, y, size / 2); //제 2사분면
				recur(x, y + size / 2, size / 2); //제 3사분면
				recur(x + size / 2, y, size / 2); //제 1사분면
				recur(x + size / 2, y + size / 2, size / 2); //제 4사분면
				cout << ')';
				return;
			}
		}
	}
	cout << color;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	recur(0, 0, N);
}