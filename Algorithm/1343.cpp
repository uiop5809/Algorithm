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
	string board;
	string result = "";
	int cnt = 0;

	cin >> board;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 'X') {
			cnt++;
		}
		if (board[i] == '.' || i == board.size() - 1) {
			while (cnt > 0) {
				if (cnt % 2 == 0) {
					if (cnt >= 4) {
						result += "AAAA";
						cnt -= 4;
					}
					else {
						result += "BB";
						cnt -= 2;
					}
				}
				else {
					result = "-1";
					break;
				}
			}
		}
		if (result == "-1") {
			break;
		}
		if (board[i] == '.') {
			result += '.';
		}
	}
	cout << result;
}