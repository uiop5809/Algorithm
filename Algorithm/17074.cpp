#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int a;
	long long count = 0;
	long long sum = 0;

	scanf("%d", &a);
	vector <long long> nums(a);
	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		nums[i] = num;
	}
	vector <vector <long long>> newnums(a);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (i != j) {
				newnums[i].push_back(nums[j]);
			}
		}
	}
	for (int i = 0; i < a; i++) {
		count = 0;
		for (int j = 0; j < newnums[i].size() - 1; j++) {
			if (newnums[i][j] > newnums[i][j + 1]) {
				count++;
			}
		}
		if (count == 0) {
			sum++;
		}
	}
	printf("%lld", sum);
}