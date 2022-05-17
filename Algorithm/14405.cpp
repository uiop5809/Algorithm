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
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'p') {
			if (str[i + 1] == 'i') i += 1;
			else flag = true;
		}
		else if (str[i] == 'k') {
			if (str[i + 1] == 'a') i += 1;
			else flag = true;
		}
		else if (str[i] == 'c') {
			if (str[i + 1] == 'h' && str[i + 2] == 'u') i += 2;
			else flag = true;
		}
		else flag = true;
	}
	if (!flag) cout << "YES";
	else cout << "NO";
}