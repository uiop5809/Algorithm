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

unsigned long long N;

int binary_search(long long left, long long right) {

	while (left <= right) {
		int mid = (left + right) / 2;
		if (mid * mid == N) {
			return mid;
		}
		else if (mid * mid > N) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	cout << binary_search(0, N);
}