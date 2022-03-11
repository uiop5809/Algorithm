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

int A, B, C;
const int p[6] = { 2, 4, 8, 16, 32, 64 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;
	int cnt = 0, p_cnt = 0;
	for (int x = -100; x <= 100; x++) {
		if (A * x * x + B * x + C == 0) {
			cnt++;
			for (int i = 0; i < 6; i++) {
				if (x == p[i]) p_cnt++;
			}
		}
	}

	if (cnt != 2) cout << "둘다틀렸근";
	else if (p_cnt == 2) cout << "이수근";
	else cout << "정수근";
}