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

long long num[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i <= N; i++) {
		num[i] = (num[i - 1] + num[i - 2]) % 15746;
	}
	cout << num[N];
}