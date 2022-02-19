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

int dpa[46], dpb[46];
int a = 0, b = 0;

void dynamic(int K) {
	dpa[1] = 0;
	dpa[2] = 1;
	dpb[1] = 1;
	dpb[2] = 1;

	for (int i = 3; i <= K; i++) {
		dpa[i] = dpa[i - 1] + dpa[i - 2];
		dpb[i] = dpb[i - 1] + dpb[i - 2];
	}
}

int main() {
	int K;

	cin >> K;
	dynamic(K);
	cout << dpa[K] << " " << dpb[K];
}