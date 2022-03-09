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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, num;
	int res[11] = { 0 };
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num;

		for (int j = 1; j <= N; j++) {
			if (num == 0 && res[j] == 0) {
				res[j] = i;
				break;
			}
			else if (res[j] == 0) {
				num--;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << res[i] << " ";
	}
}