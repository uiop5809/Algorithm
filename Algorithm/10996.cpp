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
	int n;

	cin >> n;
	if (n == 1) {
		cout << "*";
	}
	else {
		for (int i = 1; i <= 2 * n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
				else {
					if (j % 2 == 0) {
						cout << " ";
					}
					else {
						cout << "*";
					}
				}
			}
			cout << "\n";
		}
	}
}