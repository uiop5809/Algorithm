#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int T, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> a >> b;
		int res = 1;
		for (int i = 0; i < b; i++) {
			res = (res * a) % 10;
		}
		if (res == 0) cout << 10 << "\n";
		else cout << res << "\n";
	}
}