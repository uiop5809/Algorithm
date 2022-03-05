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

int num[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		if (num[i] > num[i + 1]) {
			int temp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = temp;
			
			for (int j = 0; j < 5; j++) {
				cout << num[j] << " ";
			}
			cout << "\n";
		}
		if (i == 3) {
			for (int j = 0; j < 5; j++) {
				if (num[j] != j + 1) {
					i = -1;
				}
			}
		}
	}
}