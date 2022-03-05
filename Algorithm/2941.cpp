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

	string str;
	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		cnt++;
		if (str[i] == '-' || str[i] == '=') {
			cnt--;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j' || str[i] == 'l' && str[i + 1] == 'j') {
			cnt--;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			cnt--;
		}
	}

	cout << cnt;
}