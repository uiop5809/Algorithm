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
	int M, N, num, sum = 0, res;
	int min = 99999;

	cin >> M >> N;
	for (int i = ceil(sqrt(M)); i <= floor(sqrt(N)); i++) {
		if (i) {
			num = pow(i, 2);
			sum += num;

			if (num < min) {
				min = num;
				res = min;
			}
		}
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << res;
	}
}