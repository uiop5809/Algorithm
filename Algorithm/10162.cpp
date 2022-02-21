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
	int num, no = 0;
	int a = 0, b = 0, c = 0;

	cin >> num;
	while (num > 0) {
		if (num / 300 > 0) {
			num -= 300;
			a++;
		}
		else if (num / 60 > 0) {
			num -= 60;
			b++;
		}
		else if (num / 10 > 0) {
			num -= 10;
			c++;
		}
		else {
			no++;
			break;
		}
	}

	if (no == 1) {
		cout << -1;
	}
	else {
		cout << a << " " << b << " " << c;
	}
}