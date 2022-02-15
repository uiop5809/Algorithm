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

int T, num, cnt = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	stack <int> s;
	vector <char> v;

	cin >> T;
	while (T--) {
		cin >> num;

		while(cnt <= num){
			s.push(cnt);
			cnt++;
			v.push_back('+');
		}
		if (s.top() == num) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}