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
	int N;
	string str;

	cin >> N;
	while (N--) {
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				str[i] += 32;
			}
		}
		cout << str << "\n";
	}
}