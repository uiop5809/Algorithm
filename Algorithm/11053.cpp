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
	int N, n;
	vector <int> num;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num.push_back(n);
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());

	cout << num.size();
}