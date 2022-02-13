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
	int a;
	int cnt = 0;
	int num[100001];
	int num1[53] = { 0 };
	int num2[53] = { 0 };
	char str[100001];

	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &num[i]);
		num1[num[i]]++;
	}
	getchar();
	scanf("%[^\n]s", str);
	for (int i = 0; i < a; i++) {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] -= 64;
		}
		else if (97 <= str[i] && str[i] <= 122) {
			str[i] -= 70;
		}
		else { //¶ç¾î¾²±â
			str[i] -= 32;
		}
	}
	for (int i = 0; i < a; i++) {
		num2[str[i]]++;
	}
	for (int i = 0; i < 53; i++) {
		if (num1[i] != num2[i]) {
			cnt++;
		}
	}
	if (cnt == 0) {
		printf("y");
	}
	else {
		printf("n");
	}
}
