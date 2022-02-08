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
	int a, b;
	int sum = 0;

	cin >> a >> b;
	vector <int> v;
	for (int i = 1; i <= 45; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i);
		}
	}
	for (int i = a - 1; i < b; i++) {
		sum += v[i];
	}
	cout << sum;
}