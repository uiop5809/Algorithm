#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int T, n;

bool isPrime(int i) {
	if (i == 1) return false;
	if (i == 2) return true;
	for (int j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n;
		int max = 0, min = 10000;
		for (int i = 2; i <= n / 2; i++) {
			if (isPrime(i) && isPrime(n - i)) {
				if (max < i) max = i;
				if (min > n - i) min = n - i;
			}
		}
		cout << max << " " << min << "\n";
	}
}