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

int result[3];
int map[2200][2200];

bool check(int row, int col, int num) {
	// Ω√¿€¡°
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])
				return false;
		}
	}
	return true;
}

void divide(int ros, int col, int num) {
	int(check(row, col, num)) {
		result[map[row][col]]++;
	}
	else {
	int size = num / 3;

	for ()
}
}