#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

char c;
string str;

int main() {
	while (c != '#') {
		cin >> c;
		if (c == '#') break;
		getline(cin, str);
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (c == str[i] || c - 32 == str[i]) cnt++;
		}
		cout << c << " " << cnt << "\n";
	}
}