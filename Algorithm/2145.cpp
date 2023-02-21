#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

string str;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (str != "0") {
		cin >> str;
		if (str == "0") break;
		for (int i = 0; i < str.size(); i++) {
			sum += str[i] - '0';

			if (i == str.size() - 1) {
				str = to_string(sum);
				i = -1;
				sum = 0;
			}
			if (str.size() == 1) break;
		}
		cout << str << "\n";
	}
}