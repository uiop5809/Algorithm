#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int a, b;
	int num[101][101];
	int gsum = 0, ssum = 0, ksum = 0;
	int sum = 0;

	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	for (int i = 0; i < a; i++) { //°¡·Î
		for (int j = 0; j < b - 1; j++) {
			if (num[i][j + 1] - num[i][j] > 0) {
				gsum += num[i][j + 1] - num[i][j];
			}
		}
	}
	for (int i = 0; i < b; i++) { //¼¼·Î
		for (int j = 0; j < a - 1; j++) {
			if (num[j + 1][i] - num[j][i] > 0) {
				ssum += num[j + 1][i] - num[j][i];
			}
		}
	}
	for (int i = 0; i < b; i++) {
		sum += num[0][i];
	}
	for (int i = 0; i < a; i++) {
		sum += num[i][0];
	}
	ksum = a * b * 2; //À­¸é, ¾Æ·§¸é
	printf("%d", gsum * 2 + ssum * 2 + sum * 2 + ksum);
}