#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;

	while (cin >> str) {
		if (str == "") break;
		for (int i = 0; i < str.size(); i++) {
			alpha[str[i] - 'a']++;
		}
	}

	int max = 0, res;
	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			res = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) {
			res = i;
			cout << (char)(res + 'a');
		}
	}
}