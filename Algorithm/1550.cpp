#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num = 0;
	string s;
	cin >> s;

	int size = s.size() - 1;
	int sum = 0;
	for (int i = 0; i < s.length(); ++i) {
		num = pow(16, size);
		size--;

		if ('A' <= s[i] && s[i] <= 'F') {
			sum += num * (s[i] - 'A' + 10);
		}
		else {
			sum += num * (s[i] - '0');
		}
	}
	cout << sum;
}