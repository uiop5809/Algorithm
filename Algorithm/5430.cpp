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

int T, n, cnt=0;
string str, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> str;
		cin >> n;
		cin >> b;

		deque <int> d;
		string temp = ""; //두 자릿수 이상 숫자를 위해
		for (int i = 0; i < b.length(); i++) {
			if (b[i] == '[') {
				continue;
			}
			else if ('0' <= b[i] && b[i] <= '9') {
				temp += b[i];
			}
			else if (b[i] == ',' || b[i] == ']')
			{
				if (!temp.empty())
				{
					d.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool flag = true;
		bool isEmpty = false;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') {
				flag = !flag;
			}
			else if (str[i] == 'D') {
				if (!d.empty()) {
					if (flag) {
						d.pop_front();
					}
					else {
						d.pop_back();
					}
				}
				else {
					isEmpty = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (!isEmpty) {
			cout << "[";
			if (flag) {
				while (!d.empty()) {
					cout << d.front();
					d.pop_front();
					if (!d.empty()) {
						cout << ",";
					}
				}
			}
			else {
				while (!d.empty()) {
					cout << d.back();
					d.pop_back();
					if (!d.empty()) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
	}
}