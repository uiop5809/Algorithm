#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt1 = 0, cnt2 = 0; // happy, sad
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ':' && str[i + 1] == '-') {
			if (str[i + 2] == ')') cnt1++;
			else if (str[i + 2] == '(') cnt2++;
		}
	}
	if (!cnt1 && !cnt2) cout << "none";
	else {
		if (cnt1 == cnt2) cout << "unsure";
		else if (cnt1 < cnt2) cout << "sad";
		else if (cnt1 > cnt2) cout << "happy";
	}
}