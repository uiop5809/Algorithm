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

int N, x, y;
int a[101];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> x >> y;

	cout << (double)x / 100 * N << " ";
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] >= y) {
			cnt++;
		}
	}
	cout << cnt;
}