#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int a;
	int num1[100001], num2[100001];
	int min = 100000;
	int max = -1;
	int g;

	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &num1[i], &num2[i]);
		if (num2[i] < min) { //�ϱ��ð�
			min = num2[i];
		}
		if (num1[i] > max) { //��ð�
			max = num1[i];
		}
	}
	g = max - min; //��ð��� �ִ밪-�ϱ��ð��� �ּҰ�

	if (g < 0) {
		printf("%d", 0);
	}
	else {
		printf("%d", g);
	}
}