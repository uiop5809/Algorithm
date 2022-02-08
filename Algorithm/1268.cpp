#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int a;
	int num[1001][5];
	int sum[1001] = { 0 };
	int res;
	int max = 0;

	cin >> a;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 0; i < a; i++) { //학생수
		for (int j = 0; j < a; j++) { //다른 학생
			for (int k = 0; k < 5; k++) { //학년
				if (num[i][k] == num[j][k]) {
					sum[i]++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < a; i++) {
		cout << " " << sum[i];
	}
	for (int i = 0; i < a; i++) {
		if (max < sum[i]) {
			max = sum[i];
			res = i + 1;
		}
		else if (sum[i] == max) { //여러명
			if (res > i + 1) {
				res = i + 1;
			}
		}
	}
	cout << res;
}