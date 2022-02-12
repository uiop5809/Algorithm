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

int T, num[3];

int main() {
	cin >> T;

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num[j];
		}
		sort(num, num + 3);

		cout << "Scenario #" << i << ":\n";
		if (pow(num[2],2) == pow(num[0], 2) + pow(num[1], 2)) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
		cout << "\n";
	}
}