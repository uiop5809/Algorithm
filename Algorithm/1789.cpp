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
	long long S;
	long long sum = 0;
	int num = 1, cnt = 0;

	cin >> S;
	while (1) {
		sum += num;
		cnt++;
		if (sum > S) {
			cnt--;
			break;
		}
		num++;
	}
	cout << cnt;
}