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
	cin.tie(NULL), cout.tie(NULL);

	int N, num;
	cin >> N;
	
	stack <pair <int, int>> s;
	vector <int> res(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> num;

		if (s.empty()) {
			s.push({ i, num });
		}
		else {
			while (!s.empty() && s.top().second < num) {
				res[s.top().second] = num;
				s.pop();
			}
			s.push({i, num});
		}
	}

	while (!s.empty()) {
		auto top = s.top();
		s.pop();

		res[top.second] = -1;
	}

	for (auto it : res) {
		cout << it << " ";
	}
}