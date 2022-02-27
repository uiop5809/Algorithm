#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}
	cout << cnt;
}