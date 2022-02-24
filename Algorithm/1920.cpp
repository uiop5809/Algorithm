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

int N, M, num, a[100001];

int binary_search(int left, int right, int find) {
	while (left <= right) {
		int mid;
		mid = (left + right) / 2;

		if (find == a[mid]) {
			return 1;
		}
		else if (find > a[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << binary_search(0, N - 1, num) << "\n";
	}

}