#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string ans;
	int max = 0;
	while (1) {
		string str;
		cin >> str;
		if (str == "E-N-D") break;

		// 대문자를 소문자로
		for (int i = 0; i < str.size(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				str[i] += 32;
			}
		}
		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if ('a' <= str[i] && str[i] <= 'z' || str[i] == '-') {
				temp += str[i];
			}
			else {
				if (temp.size() > max) {
					max = temp.size();
					ans = temp;
				}
				temp = "";
			}
		}
		if (temp != "") {
			if (temp.size() > max) {
				max = temp.size();
				ans = temp;
			}
		}
	}
	cout << ans;
}