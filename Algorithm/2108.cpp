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
	int T;
	int sum = 0, max = 0, mostv = 0, cnt = 0;
	float ave;

	cin >> T;
	vector <int> num(T);
	vector <int> v(8001);
	for (int i = 0; i < T; i++) {
		cin >> num[i];
	}
	//»ê¼úÆò±Õ
	for (int i = 0; i < T; i++) {
		sum += num[i];
		ave = sum / (float)T;
		v[num[i] + 4000]++;
	}
	cout << round(ave) << "\n";

	//Áß¾Ó°ª
	sort(num.begin(), num.end());
	cout << num[T / 2] << "\n";

	//ÃÖºó°ª
	for (int i = 0; i < 8001; i++) {
		if (v[i] == 0) {
			continue;
		}
		else if (max < v[i]) {
			max = v[i];
			mostv = i - 4000;
		}
	}
	for (int i = 0; i < 8001; i++) {
		if (max == v[i]) {
			cnt++;
		}
		if (cnt == 2) {
			mostv = i - 4000;
			break;
		}
	}
	cout << mostv << "\n";

	//¹üÀ§
	cout << num[T - 1] - num[0];
}