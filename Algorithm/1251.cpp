#include <iostream>
#include <string>
using namespace std;

string str;

string rever(string str) {
	int s = str.size();
	char temp;
	for (int i = 0; i < s / 2; i++) {
		temp = str[i];
		str[i] = str[s - i - 1];
		str[s - i - 1] = temp;
	}
	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	string a, b, c, res = "";
	for (int i = 1; i < str.size() - 1; i++) {
		for (int j = 1; j < str.size() - i; j++) {
			// substr(시작지점, 길이)
			a = str.substr(0, i);
			b = str.substr(i, j);
			c = str.substr(i + j); // 시작지점부터 끝까지
			a = rever(a);
			b = rever(b);
			c = rever(c);

			if (res == "") res = a + b + c;
			else if (res > a + b + c) res = a + b + c;
		}
	}
	cout << res;
}