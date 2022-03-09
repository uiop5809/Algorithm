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

int N, M;
int num[51][51];

int square() {
	int res = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N, M); k++) {
				if (i + k < N && j + k < M){
					if (num[i + k][j] == num[i][j] && num[i + k][j + k] == num[i][j] && num[i][j + k] == num[i][j]) {
						res = max(res, k + 1);
					}
				}
			}
		}
	}
	return res * res;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &num[i][j]);
		}
	}
	cout << square();
}