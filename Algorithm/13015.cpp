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
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "*";
	}
	for (int i = 0; i < 2 * n - 3; i++) {
		cout << " ";
	}
	for (int i = 0; i < n; i++) {
		cout << "*";
	}
	cout << "\n";

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < n - 2; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * n - 5 - 2 * i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < n - 2; j++) {
			cout << " ";
		}
		cout << "*";
		cout << "\n";
	}

	for (int i = 0; i < n - 1; i++) {
		cout << " ";
	}
	cout << "*";
	for (int j = 0; j < n - 2; j++) {
		cout << " ";
	}
	cout << "*";
	for (int j = 0; j < n - 2; j++) {
		cout << " ";
	}
	cout << "*";
	cout << "\n";

	for (int i = 0; i < n - 2; i++) {
		for (int j = n - 2 - i; j > 0; j--) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < n - 2; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < n - 2; j++) {
			cout << " ";
		}
		cout << "*";

		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		cout << "*";
	}
	for (int i = 0; i < 2 * n - 3; i++) {
		cout << " ";
	}
	for (int i = 0; i < n; i++) {
		cout << "*";
	}
}