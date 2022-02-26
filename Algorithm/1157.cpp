#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	char str[1000001];
	int num1[27] = { 0 };
	int max = 0;
	int cnt = 0, num2;

	scanf("%s", str);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == i + 65 || str[j] == i + 97) {
				num1[i]++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max < num1[i]) {
			max = num1[i];
			num2 = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (num1[i] == max) {
			cnt++;
		}
	}
	if (cnt > 1) {
		printf("?");
	}
	else {
		printf("%c", num2 + 65);
	}
}