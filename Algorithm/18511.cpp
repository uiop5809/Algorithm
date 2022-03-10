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

int n, k, ans;
int num;
vector <int> v(k);

void recursive(int num, int ten) {
	if (num > n) {
		return;
	}
	ans = max(ans, num);

	for (int i = 0; i < v.size(); i++) {
		recursive(num + ten * v[i], ten * 10);
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	recursive(0, 1);
	cout << ans;

	return 0;
}