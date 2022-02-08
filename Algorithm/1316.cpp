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
	int n;
	int cnt = 0;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		bool flag = true;

		for (int j = 0; j < str.size(); j++) {
			for (int k = 0; k < j; k++) {
				if (str[j] != str[j - 1] && str[j] == str[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) cnt++;
	}
	cout << cnt;
}