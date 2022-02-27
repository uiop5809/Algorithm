#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		map <string, int> m;
		while (n--){
			string name, kind;
			cin >> name >> kind;

			m[kind]++;
		}

		int res = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++)
			res *= (iter -> second + 1);

		cout << res - 1 << "\n";
	}
}