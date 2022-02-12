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

int white, blue;
int cp[130][130];

void get_cnt(int x, int y, int size) {
	int color = cp[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (cp[i][j] != color) {
				get_cnt(x, y, size / 2); //제 2사분면
				get_cnt(x, y + (size / 2), size / 2); //제 1사분면
				get_cnt(x + (size / 2), y, size / 2); //제 3사분면
				get_cnt(x + (size / 2), y + (size / 2), size / 2); //제 4사분면
				return;
			}
		}
	}
	if (color == 1) {
		blue++;
	}
	else {
		white++;
	}
}

int main() {
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cp[i][j];
		}
	}
	get_cnt(0, 0, n);
	cout << white << "\n" << blue;
}