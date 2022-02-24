#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	
	set <string> s;
	while (n--) {
		string name, state;
		cin >> name >> state;

		if (state == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
		cout << *iter << "\n";
	}
}