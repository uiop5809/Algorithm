#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int num, num1, num2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		cin >> num;
		if (i < 4) num1 += num;
		else num2 += num;
	}
	cout << max(num1, num2);
}