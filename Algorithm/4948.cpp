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

int n, c[250000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1){
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i <= sqrt(2 * n); i++) {
			if (c[i]) continue;
			for (int j = i * i; j <= 2 * n; j += i) {
				if (c[j]) continue;
				c[j] = 1;
			}
		}
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!c[i]) cnt++;
		}
		cout << cnt << "\n";
	}
}