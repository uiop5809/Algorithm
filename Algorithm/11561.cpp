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
typedef unsigned long long ull;

ull T, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;

		ull left = 1, right = N;
		while (left <= right) {
			ull mid = (left + right) / 2;
			ull a = (mid * (mid + 1)) / 2; //공차가 1인 등차수열 합
			if (a == N) {
				right = mid;
				break;
			}
			if (a < N) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << right << "\n";
	}
}