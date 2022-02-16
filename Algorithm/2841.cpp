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
	int N, P, cnt = 0;
	cin >> N >> P;

	stack <int> s[7];
	for (int i = 0; i < N; i++) {
		int n, p;
		cin >> n >> p;

		if (s[n].empty()) {
			s[n].push(p);
			cnt++;
		}
		else{
			if (s[n].top() < p) {
				s[n].push(p);
				cnt++;
			}
			else if (s[n].top() == p) {
				continue;
			}
			else {
				while (!s[n].empty() && s[n].top() > p) {
					s[n].pop();
					cnt++;
				}
				if (s[n].empty() || s[n].top() != p) {
					s[n].push(p);
					cnt++;
				}
			}
		}
	}
	cout << cnt;

}