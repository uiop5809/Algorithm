#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string binary(string str) {
	int sum = 0;
	int num = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		sum += (str[i] - '0') * num;
		num *= 2;
	}
	return to_string(sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	string res = "";
	int cnt = 0;

	string s = "";
	for (int i = str.size() - 1; i >= 0; i--) {
		res += str[i];
		cnt++;
		if (cnt == 3) {
			cnt = 0;
			reverse(res.begin(), res.end());
			s += binary(res);
			res = "";
		}
	}
	if (cnt != 0) {
		reverse(res.begin(), res.end());
		s += binary(res);
	}
	reverse(s.begin(), s.end());
	cout << s;
}