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

int main() {
	int a;

	cin >> a;
	for (int i = 0; i < a; i++) { //�� ��
		for (int j = 0; j < i; j++) { //����
			cout << " ";
		}
		for (int k = 0; k < 2 * a - i * 2 - 1; k++) { //�� ���
			cout << "*";
		}
		cout << "\n";
	}
}