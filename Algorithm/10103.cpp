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

int n, num1, num2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int res1 = 100;
	int res2 = 100;

	cin >> n;
	while (n--) {
		cin >> num1 >> num2;
		if (num1 > num2) {
			res2 -= num1;
		}
		else if (num1 < num2) {
			res1 -= num2;
		}
	}
	cout << res1 << "\n" << res2;
}