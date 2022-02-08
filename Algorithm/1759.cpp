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

int l, c;
char arr[16];

void recursive(int p, string str, int j, int m) {
	if (str.size() == l) {
		if (j < 2 || m < 1) {
			return;
		}
		cout << str << "\n";
	}
	for (int i = p; i < c; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			recursive(i + 1, str + arr[i], j, m + 1);
		}//모음
		else {
			recursive(i + 1, str + arr[i], j + 1, m);
		}//자음
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	recursive(0, "", 0, 0);
}