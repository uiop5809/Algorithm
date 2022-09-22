#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		getline(cin, str);

		string s = "", res = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				reverse(s.begin(), s.end());
				res += s;
				res += " ";
				s = "";
			}
			else {
				s += str[i];
			}
		}
		reverse(s.begin(), s.end());
		res += s;
		cout << res << "\n";
	}
}