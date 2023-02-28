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
		string str, astr;
		getline(cin, str);
		astr = str;
		for (int i = 0; i < str.size(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				str[i] += 32;
				astr[i] += 32;
			}
		}
		reverse(str.begin(), str.end());
		if (astr == str) cout << "Yes\n";
		else cout << "No\n";
	}
}
