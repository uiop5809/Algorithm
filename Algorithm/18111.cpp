#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int M, x;
int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string str;
	
	cin >> M;
	while(M--){
		cin >> str;

		if (str == "add") {
			cin >> x;
			if (arr[x] == 0) {
				arr[x] = 1;
			}
		}
		else if (str == "remove") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
		}
		else if (str == "check") {
			cin >> x;
			if (arr[x] == 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (str == "toggle") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else {
				arr[x] = 1;
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (str == "empty") {
			memset(arr, 0, sizeof(arr));
		}
	}
}