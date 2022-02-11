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

typedef long long ll;

ll result;

ll binary_search(ll left, ll right, ll find) {
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (pow(mid, 2) >= find) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	long long n;
	cin >> n;

	cout << binary_search(0, n, n) << "\n";
}