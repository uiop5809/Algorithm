#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (str != "END") {
		getline(cin, str);
		if (str == "END") break;

		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << "\n";
	}
}