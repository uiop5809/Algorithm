#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string binary(int idx, int n) {
	string str = "";
	while (n != 0) {
		str = to_string(n % 2) + str;
		n /= 2;
	}
	if (idx != 0) {
		while (str.size() < 3) {
			str = "0" + str;
		}
	}
	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str, res = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		res += binary(i, str[i] - '0');
	}
	if (str == "0") res = "0";
	cout << res;
}