#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string str;
		cin >> str;
		if (str == "0") break;

		int sum = 0;
		sum += str.size() + 1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '1') sum += 2;
			else if (str[i] == '0') sum += 4;
			else sum += 3;
		}
		cout << sum << "\n";
	}
}