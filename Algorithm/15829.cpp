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

#define MOD 1234567891;

int main() {
	int L;
	long long sum = 0, p = 1;
	string str;

	cin >> L;
	cin >> str;

	for (int i = 0; i < L; i++) {
		sum += ((str[i] - 96) * p) % MOD;
		p = (p * 31) % MOD;
	}
	cout << sum;
}