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

string str;
int N, dir;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
char p[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> str;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			p[i][j] = '#';
		}
	}

	int x = 50, y = 50; // 현재 위치
	int minX = 50, minY = 50;
	int maxX = 50, maxY = 50;
	
	p[x][y] = '.'; 
	for (int i = 0; i < N; i++) {
		if (str[i] == 'R') {
			dir++;
			if (dir > 3) dir = 0;
		}
		else if (str[i] == 'L') {
			dir--;
			if (dir < 0) dir = 3;
		}
		else { //str[i] == 'F'
			x += dx[dir];
			y += dy[dir];
			p[x][y] = '.';
		}
		minX = min(x, minX);
		minY = min(y, minY);
		maxX = max(x, maxX);
		maxY = max(y, maxY);
	}

	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			cout << p[i][j];
		}
		if (i != maxX) cout << "\n";
	}
}