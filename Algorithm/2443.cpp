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
	for (int i = 0; i < a; i++) { //ÁÙ ¼ö
		for (int j = 0; j < i; j++) { //¶ç¾î¾²±â
			cout << " ";
		}
		for (int k = 0; k < 2 * a - i * 2 - 1; k++) { //º° Âï±â
			cout << "*";
		}
		cout << "\n";
	}
}