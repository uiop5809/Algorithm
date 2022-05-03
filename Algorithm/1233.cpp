#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int a, b, c;
int num[81];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				num[i + j + k]++;
			}
		}
	}
	int max = 0, res = 0;
	for (int i = 1; i <= a + b + c; i++) {
		if (max < num[i]) {
			max = num[i];
			res = i;
		}
	}
	cout << res;
}