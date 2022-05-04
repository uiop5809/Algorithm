#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char m[5] = { 'a', 'e', 'i', 'o', 'u' };

	while (str != "#") {
		getline(cin, str);
		if (str == "#") break;

		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (str[i] == m[j] || str[i] == m[j] - 32) cnt++;
			}
		}
		cout << cnt << "\n";
	}
}