#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char c[5] = { 'a', 'e', 'i', 'o', 'u' };

	while (1) {
		bool flag = false;
		string str, res;
		cin >> str;
		if (str == "#") break;

		int idx = 0;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (str[i] == c[j]) {
					idx = i;
					flag = true;
					break;
				}
			}
			if (flag) {
				res = str.substr(i) + str.substr(0, i);
				break;
			}
		}
		if (!flag) cout << str + "ay\n";
		else cout << res << "ay\n";
	}
}