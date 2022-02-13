#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int a, b;
	char num[101][101];
	char newnum[101][101];

	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		scanf("%s", num[i]);
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (num[i][j] == 46) {
				newnum[b - j - 1][i] = '.';
			}
			else if (num[i][j] == 79) {
				newnum[b - j - 1][i] = 'O';
			}
			else if (num[i][j] == 45) {
				newnum[b - j - 1][i] = '|';
			}
			else if (num[i][j] == 124) {
				newnum[b - j - 1][i] = '-';
			}
			else if (num[i][j] == 47) {
				newnum[b - j - 1][i] = '\\';
			}
			else if (num[i][j] == 92) {
				newnum[b - j - 1][i] = '/';
			}
			else if (num[i][j] == 94) {
				newnum[b - j - 1][i] = '<';
			}
			else if (num[i][j] == 60) {
				newnum[b - j - 1][i] = 'v';
			}
			else if (num[i][j] == 118) {
				newnum[b - j - 1][i] = '>';
			}
			else if (num[i][j] == 62) {
				newnum[b - j - 1][i] = '^';
			}
		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			printf("%c", newnum[i][j]);
		}
		printf("\n");
	}
}