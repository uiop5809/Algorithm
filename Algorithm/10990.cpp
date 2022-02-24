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

	for (int i = 0; i < n - 1; i++) {
		cout << " ";
	}
	cout << "*\n";

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 2; j++) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << " ";
		}
		cout << "*";
		cout << "\n";
	}
}