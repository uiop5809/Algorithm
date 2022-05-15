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

int N, H, W;
string str[11];
char res[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> H >> W;
	for (int i = 1; i <= H; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < N; i++) {
		res[i] = '?';
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j < N * W; j++) {
			if (str[i][j] != '?') {
				res[j / W] = str[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << res[i];
	}
}