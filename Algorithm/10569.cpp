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

int T, V, E;

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;

		cout << 2 - V + E << "\n";
	}
}